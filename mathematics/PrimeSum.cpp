#include<bits/stdc++.h>
using namespace std;

typedef long int ll;
const ll MAXN = 1e6;
bool prime[MAXN+42];

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
        if (exp & 1)
            result = mulMod(result, base, mod);
        base = mulMod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

//returns random number in range [low, high]
ll randomNumber(const ll &low, const ll &high) {
    static bool first = true;
    if(first) {
        srand( time(NULL) ); //seeding for the first cast
        first = false;
    }
    return low + rand() % ((high+1) - low);
}

// https://en.wikipedia.org/wiki/Fermat%27s_little_theorem
// Fermat's little theorem states that if p is a prime number, 
// then for any integer a, the number ap − a is an integer multiple of p
bool fermatTest(const ll &n) {
    if(n<4)
        return (n==2 || n==3);
    
    for(int i=0; i<4; i++) {
        ll x = randomNumber(2,n-2); cerr << x << endl;
        if(powMod(x,n-1,n) != 1)
            return false;
    }
    return true;
}

// https://en.wikipedia.org/wiki/Goldbach%27s_conjecture
// Goldbach's conjecture states that every even whole number 
// greater than 2 is the sum of two prime numbers
bool check(ll n, ll k) {
    if(n < 2*k) //the sum of k primes is at least 2k
        return false;
    if(k == 1) 
        return fermatTest(n) ? true : false;
    if(k == 2) {
		// by Goldbach's conjecture for odd n:
		// true if n-2 is prime
		// only one even prime (2); sum of two odd primes is even
		// therefore one of the primes in the sum must be 2
        if(n&1)
            return fermatTest(n-2) ? true : false;
    
		// by Goldbach's conjecture for even n:
        return true;
    }
	
	// for n>=2k && k>=3n always true by Goldbach's conjecture because: 
	// if n is even it is the sum of k primes 2+2+2+...
	// if n is odd it is the sum of k primes 3+2+2+...
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    ll n, k;
    while(t--) {
        cin >> n >> k;            
        
        cout << (check(n,k) ? "Yes" : "No") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/prime-sum/problem