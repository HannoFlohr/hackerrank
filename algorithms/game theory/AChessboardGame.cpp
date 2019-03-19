#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board (19, vector<char>(19,'.'));

void setup() {
    int dia = 3;
    while(dia <= 17) {
        for(int i=2; i<=dia; i++) {
            for(int j=2; j<=dia; j++) {
                if(board[i-2][j-1] == '.' && board[i-2][j+1] == '.' &&
                    board[i-1][j-2] == '.' && board[i+1][j-2] == '.') {
                        board[i][j] = 'L';
                }
                else if(board[i-2][j-1] == 'L' || board[i-2][j+1] == 'L' ||
                    board[i-1][j-2] == 'L' || board[i+1][j-2] == 'L') {
                        board[i][j] = 'W';
                }
                else board[i][j] = 'L';
            }
        }
        dia += 2;
    }
    for(int i=2; i<=17; i++) {
        for(int j=2; j<=17; j++)
            cout << board[i][j] << " ";
        cout<<endl;
    }
}

// created board with winning/losing states
// than you can see pattern of winning states with positions x/y mod 4

int main()
{
    int t,x,y;
    cin >> t;
    //setup();
    while(t--) {
        cin >> x >> y;
        x %= 4;
        y %= 4;
        if(y==0 || y==3 || x==0 || x==3) 
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}
