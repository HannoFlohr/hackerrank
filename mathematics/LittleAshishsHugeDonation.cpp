#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

//returns the sum of squares for the first n elements
ull sos(ull n) {
    return n * (n+1) * (2*n+1) / 6;
}

int main()
{
    ull t, x, lower, upper, m;
    cin >> t;
    while(t--) {
        cin >> x;
        lower = 0;
        /*
        sums of squares of first n elements: x = n * (n + 1) * (2n + 1) / 6
        -> 2n^3 + 3n^2 + n = 6x
           2n^3 + C = 6x
           n^3 + C = 3x
           n^3 <= 3x
        -> upper limit at 3x^(1/3)
        */
        upper = pow(3 * x, 1 / 3.0);

        while(lower < upper) {
            m = floor((lower+upper) / 2);
            if(sos(m) < x)
                lower = m + 1;
            else if(sos(m) > x)
                upper = m - 1;
            else 
                break;
        }

        cout << (sos(m+1)<=x ? m+1 : m) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/little-chammys-huge-donation/problem