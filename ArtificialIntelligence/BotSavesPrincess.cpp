#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int x=floor(n/2);
    int y=floor(n/2);
    
    if(grid[0][0]=='p' || grid[0][n-1]=='p') {
        while(x>0) {
            cout << "UP" << endl;
            x--;
        }   
    }
    else {
        while(x<n-1) {
            cout << "DOWN" << endl;
            x++;
        }
    }
    if(grid[0][0]=='p' || grid[n-1][0]=='p') {
        while(y>0) {
                cout << "LEFT" << endl;
                y--;
            }
    }
    else {
        while(y<n-1) {
            cout << "RIGHT" << endl;
            y++;
        }
    }
    
}

int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}