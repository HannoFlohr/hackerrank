#include<bits/stdc++.h>
using namespace std;

const int MAXN = 500+5;

int perimeter(int x, int y){
    return (x+y)*2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int m, n;
    cin >> m >> n; 
    
    char plot [MAXN][MAXN];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin >> plot[i][j];

    //build matrices that store the maximum horizontal/vertical fence span at each [i][j]
    vector<vector<int>> dp_horizontal (MAXN, vector<int>(MAXN,0));
    vector<vector<int>> dp_vertical (MAXN, vector<int>(MAXN,0));
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) {
                dp_horizontal[i][j] = plot[i][j]=='x' ? 0 : dp_horizontal[i][j-1]+1;
                dp_vertical[i][j] = plot[i][j]=='x' ? 0 : dp_vertical[i-1][j]+1;
            }

    const int maxPerimeter = perimeter(n-1,m-1);
    int curPerimeter, maxPerimeterFound = -1;
    //loop through all [i][j] starting at top left corner and compute perimeter at every step to find maximum perimeter
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) 
            for(int k=dp_vertical[i][j]-1; k>=1; k--) 
                for(int l = min(dp_horizontal[i][j], dp_horizontal[i-k][j])-1; l>=1; l--) {
                    if(dp_vertical[i][j-l] > k) {
                        if( perimeter(l, k) > maxPerimeterFound )
                            maxPerimeterFound = perimeter(l, k);
                        
                        //biggest possible perimeter for m*n found
                        if(maxPerimeterFound == maxPerimeter) { 
                            cout << maxPerimeter;
                            return 0;
                        }
                        
                        break;
                    }
                }
             
    (maxPerimeterFound > 0) ? cout << maxPerimeterFound << endl : cout << "impossible" << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/mr-k-marsh/problem