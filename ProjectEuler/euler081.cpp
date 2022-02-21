#include<bits/stdc++.h>
using namespace std;

int main() {
    //time_t start = clock();
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned int n, i, j;
    cin >> n;
    vector<vector<unsigned>> value (n+1, vector<unsigned>(n+1, 0));
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) 
            cin >> value[i][j];
    
    //compute the minimal path sum traversing from top left to bottom right
    //can only move right or down
    // path_sum(x,y) = value(x,y) + min(path_sum(x,y-1), path_sum(x-1,y))
    vector<vector<unsigned long>> path_sum (n+1, vector<unsigned long>(n+1,0));
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            path_sum[i][j] = value[i][j];
            if(i==1 && j>1)
                path_sum[i][j] += path_sum[i][j-1];
            if(j==1 && i>1)
                path_sum[i][j] += path_sum[i-1][j];
            if(i>1 && j>1)
                path_sum[i][j] += min(path_sum[i][j-1], path_sum[i-1][j]);
        }
    }
    
    //result already in bottom right cell
    cout << path_sum[n][n] << endl;

    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler081/problem