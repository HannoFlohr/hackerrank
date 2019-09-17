#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> primes;
const int MAXN = 500001;

//returns the amount of possible conjectures for 'n'
int checkConjecture(int n) {
    int current, conjectureCount = 0;
    
    for(auto p : primes) {
        if(p >= n) break;

        for(int base=1; ; base++) {
            current = p + 2 * base * base;
            if(current > n)
                break;
            if(current == n) { 
                conjectureCount++;
                break;
            }
        }
    }

    return conjectureCount;
}

int main() {

    //set primes vector with sieve method
    bool prime[MAXN];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<MAXN; p++) 
        if(prime[p]) 
            for(int i=p*p; i<MAXN; i+=p)
                prime[i] = false;
    for(int p=2; p<MAXN; p++) 
        if(prime[p])
            primes.push_back(p);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n; 
        cout << checkConjecture(n) << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler046/problem