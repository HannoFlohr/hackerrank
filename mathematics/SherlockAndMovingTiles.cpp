#include <bits/stdc++.h>
using namespace std;

int main()
{   
    double l, s1, s2, q, qi;
    cin >> l >> s1 >> s2 >> q;
    while(q--) {
        cin >> qi;
        cout << std::fixed;
        cout << (double)(sqrt(2) * ( (l - sqrt(qi)) / abs(s1-s2) ) ) << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/sherlock-and-moving-tiles/problem