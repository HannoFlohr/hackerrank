#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1000000009;
const int MAXN = 5001;

ll catalan[MAXN];
ll var[MAXN][MAXN];

// sets the catalan numbers % MOD up to MAXN-1
void setCatalans() {
    catalan[0] = catalan[1] = 1;
    for(int i=2; i<MAXN; i++)
        for(int j=1; j<=i; j++)
            catalan[i] = (catalan[i] + (catalan[j-1] * catalan[i-j]) % MOD) % MOD;
    
    //for(int i=1; i<6; i++) cerr<<catalan[i]<<" ";cerr<<endl;
}

void setVar() {
    for(int i=1; i<MAXN; i++)
        var[i][0] = var[i][i] = 1;
    for(int i=2; i<MAXN; i++)
        for(int j=1; j<=i; j++)
            var[i][j] = (var[i-1][j] + var[i-1][j-1]) % MOD;

    //for(int i=1; i<6; i++) {for(int j=1; j<6; j++) cerr << var[i][j] << " ";cerr<<endl;}
}

//https://en.wikipedia.org/wiki/Catalan_number
int main()
{
    //precompute catalan numbers for n <= 5000
    //catalan[n] stores the number of possible binary search trees with n different keys
    setCatalans();
    //var[n][i] stores the number of variation for BSTs with n different keys
    // and depth i
    setVar();

    vector<ll> results (MAXN, -1);

    ll t, n, count;
    cin >> t;
    while(t--) {
        cin >> n;

        if(results[n] != -1)
            cout << results[n] << endl;
        else {
            //count all possible solutions
            count = 0;
            for(int i=1; i<=n; i++) 
                count = (count + (var[n][i] * catalan[i]) % MOD) % MOD;
            
            cout << count << endl;

            results[n] = count;
        }
    }
    return 0;
}
//https://www.hackerrank.com/challenges/lucy-and-flowers/problem