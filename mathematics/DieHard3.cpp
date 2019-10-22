#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    int x;
    while(a%b!=0) {
        x = a%b;
        a = b;
        b = x;
    }
    return b;
}

int main()
{
    int t,a,b,c;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;

        //c cant be larger than both a and b
        /*c must be a multiple of the gcd of a and b
            d = gcd(a,b) -> a=dp b=dq
            m linear combination of a,b: m=ax+by=dpx+dqy=d(px+py)
            -> d divides m 
        */
        cout << ((c <= max(a,b) && c % gcd(a,b) == 0) ? "YES" : "NO") <<endl;            
    }
    return 0;
}
//https://www.hackerrank.com/challenges/die-hard-3/problem
//http://www.math.unl.edu/~tmarley1/math189/notes/Sept9notes.pdf (math source)