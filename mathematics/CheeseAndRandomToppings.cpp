#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

//computes all primes up to MAXP and stores them
const int MAXP = 100;
vector<int> primes;
void sieveOfEratosthenes() {
    vector<bool> prime(MAXP+1,true);
    for(int p=2; p*p<=MAXP; p++) 
        if(prime[p] == true) 
            for(int i=p*p; i<=MAXP; i+=p) 
                prime[i] = false;

    for(int p=2; p<=MAXP; p++) 
        if(prime[p])
            primes.push_back(p);
}

//calculates (a*b) % mod, taking into account that (a*b) might overflow
ll mulMod(ll a, ll b, ll mod) {
    ll x = 0, y = a % mod;
    while (b > 0) {
        if (b % 2 == 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

//returns (base^exp) % mod
ll powMod(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        //odd exponent a^b = a*a^(b-1)
        if (exp & 1)
            result = mulMod(result, base, mod);
        //even exponent a^b = (a*a)^(b/2)
        base = mulMod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// returns factorial for 'r', taking into account the mod 'm'
ll factMod(ll r, ll m) {
    ll result = 1;
    for(ll i=2; i<=r; i++) {
        result *= i;
        result %= m;
    }
    return result;
}

ll comb(ll n, ll r, ll m) { 
    ll result = powMod( factMod(r, m), m-2, m );
    ll x = 1;
    for(ll i=0; i<r; i++) {
        x *= n-i;
        x %= m;
    }   
    result *= x;
    result %= m;
    return result;
}

/*
chinese remainder theorem
x = a[1] (mod p[1]) 
x = a[2] (mod p[2])
...

values of a computed using lucas's theorem
*/
ll crt(vector<ll> a, vector<ll> p, ll m) {
    ll x = 0, ni;
    for(int i=0; i<p.size(); i++) {
        ni = m / p[i];
        x += ni * powMod( ni, p[i]-2, p[i] ) * a[i];
    }
    return x;
}

ll lucas_theorem(ll n, ll r, ll p) {
    ll result = 1;
    while(n > 0) {
        result *= comb(n%p, r%p, p);
        result %= p;
        n /= p;
        r /= p; 
    }
    return result;
}

ll nCr(ll n, ll r, ll m) {
    vector<ll> a, p;
    
    for(auto x:primes)
        if(m % x == 0)
            p.push_back(x);
            
    for(auto x:p)
        a.push_back( lucas_theorem(n,r,x) );
    
    return crt(a, p, m) % m;
}

/*
https://en.wikipedia.org/wiki/Lucas%27s_theorem
https://en.wikipedia.org/wiki/Chinese_remainder_theorem#Existence_and_uniqueness
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    sieveOfEratosthenes();
    
    int t;
    ll n, r, m;
    cin >> t;
    while(t--) {
        cin >> n >> r >> m;
        cout << nCr(n,r,m) << endl;
    }
    return 0;
}
https://www.hackerrank.com/challenges/cheese-and-random-toppings/problem