#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000000;
vector<int> primes (0);

void setupPrimes() {
    vector<bool> prime (MAXN+1,true);
    for(int p=2; p*p <= MAXN; p++) 
        if(prime[p]) 
            for(int i=p*p; i<=MAXN; i+=p)
                prime[i] = false;
    for(int p=2; p<=MAXN; p++)
        if(prime[p])
            primes.push_back(p);
}

int main() {
    int t,n,i;
    unsigned long long result;
    cin >> t;
    
    setupPrimes();
    
    while(t--) {
        cin >> n;
        result = 0ULL;
        i = 0;
        while(i<primes.size() && primes[i]<=n) {
            result += primes[i];
            i++;
        }
        cout << result << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler010
/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes not greater than given N
*/