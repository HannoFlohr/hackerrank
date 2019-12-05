#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, n, x, y;
    cin >> q;
    while(q--) {
        cin >> n;
        int minx=numeric_limits<int>::max(), maxx=numeric_limits<int>::min(), miny=numeric_limits<int>::max(), maxy=numeric_limits<int>::min();
        pair<int,int> points [n];

        for(int i=0; i<n; i++) {
            cin >> points[i].first >> points[i].second;
            minx = min(minx,points[i].first);
            maxx = max(maxx,points[i].first);
            miny = min(miny,points[i].second);
            maxy = max(maxy,points[i].second);
        }

        cerr<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<" "<<endl;

        bool check = true;
        for(int i=0; i<n; i++) {
            if( ! (points[i].first == minx || points[i].first == maxx ||
                points[i].second == miny || points[i].second == maxy) )
                check = false;
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/points-on-rectangle/problem