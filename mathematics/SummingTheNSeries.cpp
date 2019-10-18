#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MOD = 1e9+7;

// n^2 - (n-1)^2 = ... = 2n-1
// -> S is sum of n odd numbers -> S = n^2 
int main()
{
    int t;
    cin >> t;
    while(t--) {
        ull n, cur;
        cin >> n;
        n %= MOD;
        cout << (n*n) % MOD << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/summing-the-n-series/problem