#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char board [52][52];
int changes [52][52];

bool in_bounds(const int &i, const int &j) {
    return i>=0 && i<n && j>=0 && j<m;
}

void dfs(int i, int j, int c, int t) {
    if(!in_bounds(i, j) || c >= changes[i][j])
        return;
        
    changes[i][j] = c;
    
    if(board[i][j] == '*' || t == k)
        return;
        
    dfs(i-1, j, board[i][j] == 'U' ? c : c+1, t+1);
    dfs(i, j-1, board[i][j] == 'L' ? c : c+1, t+1);
    dfs(i+1, j, board[i][j] == 'D' ? c : c+1, t+1);
    dfs(i, j+1, board[i][j] == 'R' ? c : c+1, t+1);
}

int main()
{
    cin >> n >> m >> k;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            cin >> board[i][j];
            changes[i][j] = numeric_limits<int>::max();
        }
    
    dfs(0, 0, 0, 0);
   
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) 
            if(board[i][j] == '*') {
                cout << (changes[i][j] == numeric_limits<int>::max() ? -1 : changes[i][j]) << endl;
                return 0;
            }

    return 0;
}
//https://www.hackerrank.com/challenges/coin-on-the-table/problem?isFullScreen=true