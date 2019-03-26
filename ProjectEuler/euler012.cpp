#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

// if prime factors are a^n b^m c^o ...
// the number of divisors is (n+1)*(m+1)*(o+1)
int getPrimeFactors(int t) {
    int counter=0, primes=1;
    while(t%2==0) {
        counter++;
        t /= 2;
    }
    primes *= (counter+1);
    
    for(int i=3; i<=sqrt(t); i+=2) {
        counter = 0;
        while(t%i==0) {
            counter++;
            t /= i;
        }
        primes *= (counter+1);
    }
    
    if(t > 2) 
        primes *= 2;
    
    return primes;
}

int main() {
    int t, n, number, factors, sum=0;
    cin >> t;
    while(t--) {
        cin >> n;
        
        number = 1;
        factors = 0;
        while(factors <= n) {
            //sum of all numbers 1...n = n*(n-1)/2
            sum = number * (number+1) / 2;
            factors = getPrimeFactors(sum);
            number++;
        }
        cout << sum << endl;
    }
    return 0;
}

// https://www.hackerrank.com/contests/projecteuler/challenges/euler012