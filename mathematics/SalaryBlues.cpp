#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n, q, k;
    cin >> n >> q;

    vector<ll> a (n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    ll gcdOfSalaryDiffs = abs(a[0]-a[1]);
    for(int i=2; i<n; i++) {
        gcdOfSalaryDiffs = __gcd(gcdOfSalaryDiffs,abs(a[i]-a[i-1]));
        if(gcdOfSalaryDiffs == 1)
            break;
    }

    while(q--) {
        cin >> k;
        cout << __gcd(gcdOfSalaryDiffs, a[0] + k) << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/salary-blues/problem