#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAXP = 1e5;
ll p;
vector<ll> factorials (MAXP);

//returns (a * b) % mod
ll mulMod(ll a, ll b, ll mod=p) {
    //using optimzed gcc extension for 128bit integers
    return ((unsigned __int128)a * b) % mod;
}
//returns (base^exp) % mod
ll powMod(ll base, ll exp, ll mod=p) {
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

ll expansions(ll n) {
    ll result = 0;
    while(n) {
        n /= p;
        result +=n;
    }
    return result;
}

ll solve(ll n) {
    if(n==0) 
        return 1;
    
    ll result = solve(n/p) * factorials[n%p] % p;
    
    if((n/p) & 1)
        result = p - result;
        
    return result; 
}

//returns nCr % p
ll combinations(ll n, ll m) {
    if(expansions(n) > expansions(m) + expansions(n-m))
        return 0;
    return (solve(n) * powMod(solve(m) * solve(n-m) % p, p-2)) % p;
}

/*
problem is choose subsequence m from word of length n -> nCr problem
for each t:
- compute the factorials % p
- compute nCr(n+1,k+1) % p using Lucas's theorem
https://en.wikipedia.org/wiki/Lucas's_theorem
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, tmp;
    ll n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k >> p;
        
        factorials[0] = 1;
        for(int i=1; i<MAXP; i++) {
            tmp = i;
            while(tmp%p == 0)
                tmp/=p;
                
            factorials[i] = factorials[i-1] * tmp % p;
        }
        
        cout << combinations(n+1, k+1) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/ajob-subsequence/problem