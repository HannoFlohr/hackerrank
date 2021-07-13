#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

/*
    odd amount of primes up to n -> alice wins
    even amount or zero primes -> bob wins
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //create vector with all primes up to 10^6
    //using 'Sieve of Eratosthenes'
    bool prime[MAXN+1];
    memset(prime,true, sizeof(prime));
    for(int p=2; p*p<=MAXN; p++){
        if(prime[p] == true)
            for(int i=p*p; i<=MAXN; i+=p)
                prime[i] = false;
    }
    vector<int> primes;
    for(int p=2; p<=MAXN; p++)
        if(prime[p])
            primes.push_back(p);
    
    int g, n, i;
    cin >> g;
    while(g--) {
        cin >> n;
        i = 0;
        while(primes[i] <= n && i<primes.size())
            i++;
            
        cout << ( i%2 == 1 ? "Alice" : "Bob" ) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/alice-and-bobs-silly-game/problem