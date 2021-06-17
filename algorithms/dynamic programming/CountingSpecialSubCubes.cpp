#include<bits/stdc++.h>
using namespace std;

const int maxn = 51;
int dp [maxn][maxn][maxn][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, n, x, y, z, k, result, hlpr;
    
    cin >> q;
    while(q--) {
        cin >> n;
        
        result = 0;
    
        for(x=0; x<n; x++)
            for(y=0; y<n; y++)
                for(z=0; z<n; z++) {
                    cin >> hlpr;
                    fill_n(dp[x][y][z], 3, hlpr);
                    
                    if(hlpr == 1) result++;
                }
        
        cout << result; // output for k=1
        
        for(k=2; k<=n; k++) { 
            result = 0;
            for(x=0; x+k<=n; x++)
                for(y=0; y+k<=n; y++)
                    for(z=0; z+k<=n; z++) { 
                        dp[x][y][z][0] = max(dp[x][y][z][0], dp[x][y][z+1][0]);
                        dp[x][y][z][1] = max(dp[x][y][z][0], max(dp[x][y+1][z][1], dp[x][y+1][z+1][1]) );
                        dp[x][y][z][2] = max(dp[x][y][z][1], 
                                            max( max(dp[x+1][y][z][2], dp[x+1][y][z+1][2]), max(dp[x+1][y+1][z][2], dp[x+1][y+1][z+1][2]) ) );
                                            
                        if(dp[x][y][z][2] == k) result++;
                    }
            
            cout << " " << result; 
        }
        cout << endl;
    }
    
    return 0;
}
//https://www.hackerrank.com/challenges/counting-special-sub-cubes/problem