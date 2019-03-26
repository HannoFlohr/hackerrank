#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll sumSquareDif(const int &n) {
    ll sumOfSquares = 0, squareOfSums = 0;
    
    for(ll i=1L; i<=(ll)n; i++) {
        sumOfSquares += (i*i);
        squareOfSums += i;
    }
    squareOfSums *= squareOfSums;
    return squareOfSums - sumOfSquares;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << sumSquareDif(n) << endl;
    }
    return 0;
}

// https://www.hackerrank.com/contests/projecteuler/challenges/euler006/problem