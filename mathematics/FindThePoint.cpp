#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, px, py, qx, qy, rx, ry; 
    cin >> n;
    while(n--) {
        cin >> px >> py >> qx >> qy;
        
        rx = 2 * qx - px;
        ry = 2 * qy - py;

        cout << rx << " " << ry << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/find-point/problem