#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef unsigned long long int ull;
const ull MOD = 10000000000ULL;

/*            
 *  https://en.wikipedia.org/wiki/Exponentiation_by_squaring
*/
// modulo multiplication for large integers
ull modMul(ull x, ull y) {
    x %= MOD;
    y %= MOD;

    if(x <= 0xFFFFFFF && y <= 0xFFFFFFF) 
        return (x*y) % MOD;

    //count leading zeroes
    ull leadingZeroes = 0;
    ull m = MOD;
    while( (m & 0x8000000000000000ULL) == 0) {
        leadingZeroes++;
        m <<= 1;
    } 

    //mask all bits of mod
    ull mask = (1 << leadingZeroes) - 1;

    ull result = 0;
    while(x>0 && y>0) {
        result += (y & mask) * x;
        result %= MOD;

        y >>= leadingZeroes;
        x <<= leadingZeroes;
        x %= MOD;
    }

    return result;
}
//returns base^exp % MOD
ull powMod(ull base, ull exp) {
    ull result = 1;

    while(exp > 0) {
        // odd exponent: b^e = b*b^(e-1) 
        if(exp & 1) 
            result = modMul(result, base);

        // even exponent: b^e = (b*b)^(e/2) 
        base = modMul(base, base);
        exp >>= 1;
    }

    return result;
}

int main() {
    ull n;
    cin >> n;

    ull sum = 0;
    for(ull i=1; i<=n; i++)
        sum += powMod(i, i);

    cout << (sum % MOD) << endl;

    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler048/