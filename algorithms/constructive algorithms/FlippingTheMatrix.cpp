#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, n, result, sum, lowerSum, upperSum;
    cin >> q;

    while(q--) {
        n;
        cin >> n;

        vector<vector<int>> m = vector<vector<int>>(2*n,vector<int>(2*n)); 
        for (int i=0; i<2*n; i++) {
            for (int j=0; j<2*n; j++) {
                cin >> m[i][j];
            }
        }

        result = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                result += max(m[i][j], 
                                max(m[i][2*n-1-j],
                                    max(m[2*n-1-i][j], m[2*n-1-i][2*n-1-j] ) ) );
            }
        }

        cout << result << "\n";
    }
    return 0;
}