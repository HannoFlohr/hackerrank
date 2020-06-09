#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
typedef long long int ll;

//modular exponentiation; calculates (base^exponent) % mod
ll modExp(ll base, ll exponent) {
    ll x = 1, y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            x = (x*y) % MOD;
        y = (y*y) % MOD;
        exponent /= 2;
    }
    return x % MOD;
}

/*
amount of valid subsets for combinations of even numbers: X = 2^even - 1 (excluding empty subset)
amount of valid subsets formed by an even amount of odd numbers: Y = 2^(odd-1) - 1

all subsets: 
res = X+Y+X*Y = ... = 2^even * 2^odd - 1
substitute even = n-odd
res = 2^(n-odd+odd-1) - 1 = 2^(n-1) - 1 if an odd number exists, 2^n - 1 otherwise 
*/
int main()
{
    int n, i, x;
    cin >> n;
    //check if odd number exists
    bool oddExists = false;
    for(i=0; i<n; i++) {
        cin >> x;
        if(x%2 != 0) {
            oddExists = true;
            break; 
        }
    }

    cout << (oddExists ? (modExp(2,n-1) - 1) : (modExp(2, n) - 1) ) << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/a-chocolate-fiesta/problem