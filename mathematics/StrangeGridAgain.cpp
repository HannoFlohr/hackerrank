#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long int r, c;
    cin >> r >> c;
    r--;
    c--; cerr << r << " "<<c<<endl;
    if(r%2 == 0)
        cout << ((r/2)*10 + c*2) << endl;
    else 
        cout << ((r/2)*10 + 1 + c*2) << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/strange-grid/problem