#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll t,x1,y1,x2,y2,counter;
    cin >> t;
    while(t--) {
        cin >> x1 >> y1 >> x2 >> y2;

        /* Points P(x1,y1) Q(x2,y2)
            to move from P to Q we move b units in x direction and a units 
            in y direction
            in order to get to the next y integer value we need to move 
            b = (x1-x2)/gcd(x1-x2,y1-y2) 

            valid y integer points between P and Q:
            y = abs((x1-x2)/b) - 1
            y = abs((x1-x2)/((x1-x2)/gcd)) - 1
            y = abs(gcd) - 1;
        */
        cout << ( abs(__gcd(x1-x2,y1-y2)) - 1 ) << endl;    
    }
    return 0;
}
//https://www.hackerrank.com/challenges/harry-potter-and-the-floating-rocks/problem