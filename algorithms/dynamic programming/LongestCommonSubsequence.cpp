#include<bits/stdc++.h>
using namespace std;

int n, m, i, j;
int a[1001], b[1001];

void lcs() {
    int dp[n+1][m+1];
    
    for(i=0; i<=n; i++) 
        for(j=0; j<=m; j++) {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    
    int length = dp[n][m];
    int result[length+1];
    i=n; j=m;
    while(i>0 && j>0) {
        if(a[i-1] == b[j-1]) {
            result[length-1] = a[i-1];
            i--; j--; length--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else 
            j--;
    }
    
    for(i=0; i<dp[n][m]; i++) 
        cout << result[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(i=0; i<n; i++)
        cin >> a[i];
    for(i=0; i<m; i++)
        cin >> b[i];
    
    lcs();
    
    return 0;
}
//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem