#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    //each supply drop fits 2x2 squares -> supplydrops = n * m / 4;
    //account for odd number of squares by adding 1
    cout << (n+n%2) * (m+m%2) / 4 << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/game-with-cells/problem