#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
int main()
{
    ull n, m, x, y, z, candies=0;
    cin >> n >> m;
    while(m--) {
        cin >> x >> y >> z;
        candies += ((y-x+1) * z);
        cerr << candies<<endl;
    }
    cout << (candies/n) << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/filling-jars/problem