#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y, xfirst, yfirst;
    bool vert = true, hori = true;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        if(i==0) {
            xfirst = x;
            yfirst = y;
            continue;
        }
        if(x != xfirst) hori = false;
        if(y != yfirst) vert = false;

        if(!hori && !vert) break;
    }

    if(!hori && !vert) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/points-on-a-line/problem