#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 10001;
int primes [maxN] = {0};

bool isPrime(int i) {
    if(i<2) return false;
    
    for(int j=2; j*j<=i; j++)
        if(i%j==0) return false;
    
    return true;
}

void setPrimes() {
    int current = 1;
    int i = 2;
    while(current < maxN) {
        if(isPrime(i)) 
            primes[current++] = i;
        i++;
    }
}

int main() {
    int t, n;
    cin >> t;
    
    setPrimes(); 
    
    while(t--) {
        cin >> n; 
        cout << primes[n] << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler007