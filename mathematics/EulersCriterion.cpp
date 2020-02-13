#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

//returns a^b % m using fast exponentiation
ull powMod(ull a, ull b, ull m) {
    ull res = 1;
    while(b) {
        if(b & 1)
            res = (res * a) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int t;
    ull a, m;
    cin >> t;
    while(t--) {
        cin >> a >> m;
        if(a==0) {
            cout << "YES" << endl;
            continue;
        }
        //http://mathworld.wolfram.com/EulersCriterion.html
        cout << (powMod(a,(m-1)/2,m)==1 ? "YES" : "NO") << endl;
    }
    return 0;
}
// https://www.hackerrank.com/challenges/eulers-criterion/problem