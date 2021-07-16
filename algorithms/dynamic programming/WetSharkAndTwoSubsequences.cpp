#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int m, r, s;
    cin >> m >> r >> s;
    
    int x[m];
    for(int i=0; i<m; i++)
        cin >> x[i];
    
    int high = (r+s) / 2;
    int low = (r-s) / 2;
    
    int dp [high+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    
    if(x[0] <= high)
        dp[x[0]][1] = 1;
    
    for(int i=1; i<m; i++) {
        for(int k=1; k<=m; k++)
            dp[0][k] = 0;
        for(int j=high; j>0; j--) {
            dp[j][0] = 0;
            for(int k=1; k<=m; k++) 
                if(j >= x[i])
                    dp[j][k] = (dp[j-x[i]][k-1] + dp[j][k]) % MOD;
            
        } 
    }
    
    long long result = 0LL;
    if(low>=0 && (r+s)%2 != 1 && (r-s)%2 != 1 && r!=0)
        for(int i=0; i<=m; i++)
            result = (result + (long long)dp[high][i] * dp[low][i]) % MOD;
            
    cout << result << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/wet-shark-and-two-subsequences/problem