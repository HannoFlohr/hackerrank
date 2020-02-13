#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAX = 2000000LL;
vector<ll> primes;
bool prime [MAX];

ll longestSequence(ll a) {
    if(a==1) return 1;

    //find all factors of 'a' 
    vector<ll> factors;
    for(ll i=0; i<primes.size() and a > 1; ) {
        if(a % primes[i] == 0) {
            factors.push_back(primes[i]);
            a /= primes[i];
        }
        else 
            i++;
    }
    if(a>1) factors.push_back(a);

    ll result = 1, cur = 1;
    for(ll i=factors.size()-1; i>=0; i--) {
        cur *= factors[i];
        result += cur;
    }
    return result;
}

int main()
{
    //compute primes using sieve of eratosthenes
    memset(prime, true, sizeof(prime));
    for(ll p=2; p*p<MAX; p++) 
        if(prime[p])
            for(ll i=p*p; i<MAX; i+=p)
                prime[i] = false;
    for(ll p=2; p<MAX; p++)
        if(prime[p])
            primes.push_back(p);

    ll n,a;
    cin >> n;
    
    ll moves = 0LL;
    while(n--) {
        cin >> a;
        moves += longestSequence(a);
    }

    cout << moves << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/breaking-sticks/problem