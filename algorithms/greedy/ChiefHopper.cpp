#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,x;
    cin >> n;

    vector<int> height;
    for (int i=0; i<n; i++) {
        cin >> x;
        height.push_back(x);
    }

    int botEnergy = 0;
    for(int i=height.size()-1; i>=0; i--) 
        botEnergy = (botEnergy + height[i] + 1) / 2;
    cout << botEnergy << endl;

    return 0;
}
