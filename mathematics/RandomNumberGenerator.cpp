#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c, num, den, minv, maxv, x, y, d;
    cin >> n;
    while(n--) {
        cin >> a >> b >> c;

        if(a + b <= c) {
            num = 1;
            den = 1;
        }
        else { 
            if(a >= c && b >= c) {
                x = c * c;
                y = 2 * a * b;
                
            }
            else if(a <= c && b<=c) {
                x = 2 * a * b - ((a - c + b) * (a - c + b));
                y = 2 * a * b;
            }
            else {
                minv = min(a,b);
                maxv = max(a,b);
                x = (c * c) - ((c-minv) * (c-minv));
                y = 2 * minv * maxv;            
            }
        
            d = __gcd(x,y);
            num = x/d;
            den = y/d;
        }

        cout << num << "/" << den << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/random-number-generator/problem?isFullScreen=true