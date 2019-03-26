#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int primes[12] = {2,3,5,7,11,13,17,19,23,29,31,37};

// a number is divisible by all numbers from 1 to n IF the number is equal to the product of all prime powers p^k; p prime, p<n
long smallestMultiple(const int &n) {
    long i=0, x, counter;
    int a [40] = {0};
    while(i<12) {
        x = n;
        counter = 0L;
        while(x/primes[i] >= 1) {
            x /= primes[i];
            counter++;
        }
        a[primes[i]] = counter;
        i++;
    }
    x = 1;
    for(i=0; i<40; i++) {
        if(a[i] != 0)
            x *= pow(i,a[i]);
    }
    
    return x;
}

int main() {
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << smallestMultiple(n) << endl;
    }
    return 0;
}

// https://www.hackerrank.com/contests/projecteuler/challenges/euler005