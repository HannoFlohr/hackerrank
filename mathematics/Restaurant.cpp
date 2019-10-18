#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,l,b;
    cin >> t;
    while(t--) {
        cin >> l >> b;
        int gcd = __gcd(l,b);
        cout << (l/gcd)*(b/gcd) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/restaurant/problem