#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

const unsigned int mod = 1e9+7;
const unsigned int maxM = 1e6+1;

//modular exponentiation; calculates (base^exponent) % mod
ull modExp(ull base, ull exponent) {
    ull x = 1, y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            x = (x*y) % mod;
        y = (y*y) % mod;
        exponent /= 2;
    }
    return x % mod;
}

//returns n!%mod
ull factorial(ull n) {
    if(n<2) return 1ULL;
    return (n * factorial(n-1))%mod;
}

int main()
{

    unsigned int t,n,m;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        /*  we can move right or down -> m+n-2 total moves
			choose m-1 down moves
			-> formula: (n+m-2)! / ((n-1)! * (m-1)!)  (m+n-2)C(m-1)
            use fast exponentiation to handle the x^-1:
            x^-1 mod p = x^(p-2) mod p
        */
        ull a = factorial(n-1) * factorial(m-1);
        a %= mod;
        a = modExp(a, mod-2);
        a = factorial(n+m-2) * a;
        a %= mod;

        cout << a <<endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/matrix-tracing/problem