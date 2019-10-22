#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t, a, b, x, r, d;
    cin >> t;
    while(t--) {
        cin >> a >> b >> x;
        r = pow(a,b); 
        d = r / x;  
        cout << (abs(d*x-r) < abs((d+1)*x-r) ? (d*x) : (d+1)*x ) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/closest-number/problem