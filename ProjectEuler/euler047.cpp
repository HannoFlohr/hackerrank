#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 2000004;
vector<int> primes;
vector<int> distinctPrimes (MAXN, -1);

//returns true if integer 'n' can be split into 'k' distinct prime factors
int checkFactors(int n) {
    int distinctPrimeFactors = 0;
    while(n>1) {
        for(auto p:primes) {
            if(distinctPrimes[n] != -1) {
                distinctPrimeFactors += distinctPrimes[n];
                n = 1;
                break;
            }

            if(n%p==0) {
                distinctPrimeFactors++;
                while(n%p==0)
                    n /= p;
                break;
            }
        }
    }
    return distinctPrimeFactors;
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
        if(prime[p]) {
            primes.push_back(p);
            distinctPrimes[p] = 1;
        }

    // all 2^i only have one distinct prime
    int x=2;
    while(x < MAXN) {
        distinctPrimes[x] = 1;
        x *= 2;
    }

    int n, k;
    cin >> n >> k;

    vector<int> validNumbers;
    bool check;
    for(int i=1; i<n+k; i++) {
        //check if current integer has a valid split
        distinctPrimes[i] = checkFactors(i);
        if(i<k) continue;

        //check if last k numbers are valid, add to valid numbers if true
        check = true;
        for(int c=0; c<k; c++) 
            if(distinctPrimes[i-c] != k) {
                check = false;
                break;
            } 
        if(check) validNumbers.push_back(i-k+1);
    }

    for(auto a:validNumbers) cout << a << endl;

    return 0;
}

// https://www.hackerrank.com/contests/projecteuler/challenges/euler047