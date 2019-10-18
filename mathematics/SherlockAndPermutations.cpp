#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MOD = 1e9 + 7;

//returns base^exp % MOD
ull power(ull base, ull exp) {
    ull result = 1ULL;
    while(exp) {
        if(exp & 1) //if exponent is odd base^exp = base*base^(exp-1)
            result = (result * base) % MOD;

        //even exponent base^exp = (base*base)^(exp/2)
        base = (base * base) % MOD;
        exp >>= 1;  
    }
    return (result % MOD);
}

int main()
{
    //precompute all n! up to 2000! (m+n <= 2000)
    ull facMod [2001];
    facMod[0]=1;
    for(ull i=1; i<=2000; i++) 
         facMod[i] = (facMod[i-1] * i) % MOD;
    
    ull t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        // # of permutations: (n+m-1)! / ((m+1)! * n!)
        ull num = facMod[n+m-1];
        ull den = (facMod[m-1] * facMod[n]) % MOD;
        ull result = (num * power(den, MOD-2)) % MOD;
        cout << result << endl; 
    }

    return 0;
}
//https://www.hackerrank.com/challenges/sherlock-and-permutations/problem