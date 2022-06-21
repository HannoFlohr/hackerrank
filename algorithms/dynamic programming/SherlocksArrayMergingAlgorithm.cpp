#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MOD = 1e9+7;
const int MAXN = 1200+5;

//calculates (a*b) % mod, taking into account that (a*b) might overflow
ll mulMod(ll a, ll b) {
    ll x = 0, y = a % MOD;
    while (b > 0) {
        if (b % 2 == 1)
            x = (x + y) % MOD;
        y = (y * 2) % MOD;
        b /= 2;
    }
    return x % MOD;
}

//returns (base^exp) % mod
ll powMod(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        //odd exponent a^b = a*a^(b-1)
        if (exp & 1)
            result = mulMod(result, base);
        //even exponent a^b = (a*a)^(b/2)
        base = mulMod(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //setup factorials and inverse mod of factorials
    vector<ll> factorial (MAXN);
    //Fermats little theorem -> multiplicative inverse of a % MOD is equal to a^(MOD-2) 
    vector<ll> factorial_inv_mod (MAXN);
    factorial[0] = 1LL;
    for(int i=1; i<MAXN; i++)
        factorial[i] = (factorial[i-1] * i) % MOD;
    for(int i=0; i<MAXN; i++) 
        factorial_inv_mod[i] = powMod(factorial[i], MOD-2);
    
    int n;
    cin >> n;
    
    vector<int> m (MAXN); 
    for(int i=1; i<=n; i++)
        cin >> m[i]; 
    
	/*
	build dp[i][j] to be the number of distinct v possible using elements m1,m2,..mi when the last column has length j 
	result will then be the sum of all dp[i][1], for i=0...n-1
	*/
    vector<vector<ll>> dp (MAXN, vector<ll>(MAXN));
    dp[0][++n] = 1;
    
    for(int i=n; i>=1; i--) 
        for(int j=i-1; j>=1; j--) {
            //e.g. for m={1,3,2} last v has to be {2} 
            if(m[j] > m[j+1] && j<i-1)
                break;
                
            for(int k=0; k<=i-j; k++) {
				//use binomial coefficient and multiplicative inverse to compute possible combinations
                dp[i-j][j] += (((dp[k][i] * factorial[i-j]) % MOD) * factorial_inv_mod[i-j-k]) % MOD;
                dp[i-j][j] %= MOD;
            }
        }
    
    ll result = 0LL;
    for(int i=0; i<n; i++) {
        result += dp[i][1];
        result %= MOD;
    }    
    
    cout << result << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/sherlocks-array-merging-algorithm/problem