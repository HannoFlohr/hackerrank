#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,x,y,z;
    cin >> t;
    while(t--) {
        cin >> x >> y >> z;

        /*
            a+p=x   b+p=y   a+b+p=z
                    b=y-p   a+y-p+p=z
                            a=z-y
            p=x-a
            p=x-z+y;
        */
        cout << (x - z + y) << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/combo-meal/problem