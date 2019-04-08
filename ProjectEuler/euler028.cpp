#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ll;
const ll MOD = 1000000007;

//returns base^exponent % MOD
ll powMod(ll base, ll exponent) {
    ll result = 1;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % MOD;
            exponent--;
        }
        else {
            base = (base*base) % MOD;
            exponent /= 2;
        }
    }
    return result;
}

// if p is prime, then https://en.wikipedia.org/wiki/Fermat%27s_little_theorem applies:
// a^(p-1)  % p = 1
// (a * a^(p-2)) % p = 1
// that means a^(p-2) is the result
ll inverseModulo(ll a) {
    return powMod(a,MOD-2);
}

int main() {
    int t;
    cin >> t;
    ll n, x, sum, part1, part2, shared;
    while(t--) {
        cin >> n;
        
        x = n/2;
        x %= MOD;
        //f(x) = 8x(x+1)(2x+1)/3 + 2x(x+1) + 4x + 1

        shared = (2 * x * (x+1)) % MOD;
        //division by 3 becomes multiplication by its modulo multiplicative inverse
        part1 = ((4 * shared * (2*x + 1)) % MOD) * inverseModulo(3); 
        part2 = shared + 4 * x + 1;
        
        sum = (part1 % MOD + part2 % MOD) % MOD;

        cout << sum << endl;
    }
    return 0;
}
