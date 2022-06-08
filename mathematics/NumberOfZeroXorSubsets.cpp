#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1e9+7;

//a^b % m
ll powMod(ll a, ll b, ll m) {
    if(b == 0) 
        return 1;
    if(b == 2) 
        return (a*a) % m; 
    if(b%2 == 0)
        return powMod(powMod(a, b/2, m), 2, m);
    return (a * powMod(a, b-1, m)) % m;
}

/*
total number of subsets of {0,...,(2^n)-1}: 2^(2^n)
number of possible xors: 2^n
subsets that xor to 0: (2^(2^n)) / (2^n) = 2^((2^n) - n) 

use Fermat's little theorem to compute (https://en.wikipedia.org/wiki/Fermat's_little_theorem)
A^(M-1) = 1 (mod M) if M is a prime

to compute B^C rewrite to x*(M+1) + y
to compute A^B^C: A^(x*(M-1)+y) = A^(M-1) * A^y 
A^(M-1) = 1 (Fermats little theorem) -> need to compute A^y 
B^C = x*(M+1) + y -> y = B^C % (M-1)
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << (powMod(2, powMod(2, n, MOD-1), MOD) * powMod(powMod(2, n, MOD), MOD-2, MOD)) % MOD << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/number-of-subsets/problem