#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int points [4][3];

        for(int i=0; i<4; i++) 
            cin >> points[i][0] >> points[i][1] >> points[i][2];

        bool check = false;
        for(int i=0; i<3; i++) 
            if( points[0][i] == points[1][i] && 
                points[0][i] == points[2][i] && 
                points[0][i] == points[3][i])
                check = true;
        
        cout << (check ? "YES" : "NO") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/sherlock-and-planes/problem