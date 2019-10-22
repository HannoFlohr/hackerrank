#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll mod;

class ComplexNumber {
public:
    ll real;
    ll imag;
    ComplexNumber(ll r, ll i) : real(r), imag(i) {}
};

ll mmod(ll n) {
    return (n-(n/mod)*mod);
}

// (a + bi) * (c + di) = (ac - bd) + i (bc + ad)
ComplexNumber multiplyComplex(ComplexNumber p, ComplexNumber q) {
    ll real = mmod(p.real * q.real - p.imag * q.imag);
    ll imag = mmod(p.imag * q.real + p.real * q.imag);
    return ComplexNumber (real,imag);
}

//returns c^k 
ComplexNumber exponentiateComplex(ComplexNumber c, ll k) {
    ComplexNumber result (1,0);
    while(k>0) {
        if(k & 1)
            result = multiplyComplex(result,c);
        c = multiplyComplex(c, c);
        k >>= 1;
    }
    return result;
}

int main()
{
    ll q,a,b,k;
    cin >> q;
    while(q--) {
        cin >> a >> b >> k >> mod;

        ComplexNumber p (a,b); 
        ComplexNumber result = exponentiateComplex(p, k);
        cout << (result.real+mod)%mod << " " << (result.imag+mod)%mod << endl; 
    }
    return 0;
}
//https://www.hackerrank.com/challenges/russian-peasant-exponentiation/problem