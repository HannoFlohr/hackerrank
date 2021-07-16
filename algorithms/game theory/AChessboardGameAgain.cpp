#include<bits/stdc++.h>
using namespace std;

int grundy[18][18];

//possible moves: (-2,1) (-2,-1) (-1,2) (1,-2)
int dx[4] = {-2,-2,-1,1};
int dy[4] = {1,-1,-2,-2};

int set_grundy(int x, int y) {
    //top left corner -> no move -> grundy=0
    if(x==1 && y==1)
        return 0;
        
    //check if grundy for this cell was computed before
    if(grundy[x][y] != -1)
        return grundy[x][y];
        
    set<int> s;
    int move_x, move_y;
    for(int i=0; i<4; i++) {
        move_x = x + dx[i];
        move_y = y + dy[i];
        if(move_x>=1 && move_y>=1 && move_x<=15 && move_y<=15)
            s.insert(set_grundy(move_x, move_y));
    }
    
    //find and set the not included minimum element in the set of grundy values of possible move coordinates
    int mex = 0;
    while(s.find(mex) != s.end()) 
        mex++;
    grundy[x][y] = mex;
    
    return grundy[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    memset(grundy, -1, sizeof(grundy));
    
    int t, n, x, y, result;
    cin >> t;
    while(t--) {
        cin >> n;
        result = 0;
        
        for(int i=1; i<=n; i++) {
            cin >> x >> y;
            result ^= set_grundy(x,y);
        }
        
        cout << (result ? "First" : "Second") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/chessboard-game-again-1/problem