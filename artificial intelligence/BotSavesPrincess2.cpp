#include <iostream>
#include <vector>
using namespace std;

void nextMove(int n, int r, int c, vector <string> grid){
    int princess_r, princess_c;
    string s;
    char ch;
    bool found = false;
    for(int i=0; i<n; i++) {
        s = grid[i];
        for(int j=0; j<n; j++) {
            ch = s[j];
            if(ch=='p') {
                princess_c = j;
                princess_r = i;
                found = true;
                break;
            }
         }
        if(found) break;
    }
    
    int dif_r, dif_c;
    dif_r = princess_r - r;
    dif_c = princess_c - c;

    if(dif_r > 0) cout << "DOWN" << endl; 
    else if(dif_r < 0) cout << "UP" << endl;
    else if(dif_c > 0) cout << "RIGHT" << endl;
    else if(dif_c < 0) cout << "LEFT" << endl;
        
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}