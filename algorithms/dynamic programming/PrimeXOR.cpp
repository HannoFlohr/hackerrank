#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;
const ll MAXSIZE = 100001;
const ll MAXXOR = 8191; //highest possible xor in range
const ll RANGE = 1001; //3500...4500

vector<int> primes;
vector<vector<ll>> dp;
vector<ll> frequency;

void setPrimes() {
    vector<bool> prime (MAXXOR+1,true);
    for(int p=2; p*p<=MAXXOR; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=MAXXOR; i+=p) {
                prime[i] = false;
            }
        }
    }
    prime[0] = prime[1] = false;

    for(int i=0; i<MAXXOR+1; i++)
        if(prime[i]) primes.push_back(i);
}

int main()
{
    int q,n;
    cin >> q;

    setPrimes();

    while(q--) {
        cin >> n;

        dp = vector<vector<ll>>(RANGE+1, vector<ll>(MAXXOR+1,0));
        frequency = vector<ll>(RANGE+1, 0);

        vector<ll> v (n);
        for(int i=0; i<n; i++) {
            cin >> v[i];
            frequency[v[i]-3500]++;
        }
       
        dp[0][3500] = (frequency[0] + 1) / 2;
        dp[0][0] = (frequency[0] + 2) / 2;
        for(int i=1; i<=RANGE; i++) {
            for(int j=0; j<=MAXXOR; j++) {
                dp[i][j] = (dp[i-1][j]*((frequency[i]+2)/2) + 
                            dp[i-1][j^(i+3500)]*((frequency[i]+1)/2) ) % MOD ;
            }
        }

        ll result = 0;
        for(auto p:primes) {
            result += dp[RANGE][p];
            result %= MOD;
        }
        cout << result << endl;
    }

    return 0;
}
