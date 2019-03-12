#include <bits/stdc++.h>

using namespace std;

int cost(vector<int> b) {
    int n = b.size();
    vector<int> lowB = vector<int>(n);
    vector<int> highB = vector<int>(n);
    vector<int> maxCost = vector<int>(n);
    lowB[0] = 0;
    highB[0] = 0;
    maxCost[0] = 0;

    for(int i=1; i<n; i++) {
        lowB[i] = max(lowB[i-1], highB[i-1] + abs(b[i-1]-1) );
        highB[i] = max(highB[i-1] + abs(b[i]-b[i-1]), lowB[i-1] + abs(b[i]-1) );
        maxCost[i] = max(lowB[i], highB[i]);
    }
    return maxCost[n-1];
}

int main()
{
    int t, n, result;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> b = vector<int>(n,0);
        for(int i=0; i<n; i++) cin >> b[i];

        result = cost(b);
        cout << result << endl;
    }

    return 0;
}
