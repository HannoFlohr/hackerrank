#include <bits/stdc++.h>

using namespace std;

int checkRegion(int i, int j, vector<vector<int>> &v) {
    int region = 1;
    for(int r=i-1; r<=i+1; r++)
        for(int c=j-1; c<=j+1; c++) {
            if(r==i && c==i) continue;
            if(v[r][c] == 1) {
                v[r][c] = 2;
                region += checkRegion(r,c,v);
            } 
        }
    return region;
}

int maxRegion(vector<vector<int>> grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> v (n+2, vector<int>(m+2,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) 
            v[i+1][j+1] = grid[i][j];

    int region, regionMax = 0;
    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++)
            if(v[i][j]==1) {
                v[i][j] = 2;
                region = checkRegion(i,j,v);
                regionMax = max(regionMax, region);
            }
    }
    return regionMax;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];
    }

    int res = maxRegion(grid);

    cout << res << endl;
    return 0;
}
