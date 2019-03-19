#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, maxXor = 0;
    cin >> l >> r;
    for(int i=l; i<=r; i++) 
        for(int j=i+1; j<=r; j++) 
            maxXor = max(maxXor, i^j);
    
    cout << maxXor << endl;
    return 0;
}
