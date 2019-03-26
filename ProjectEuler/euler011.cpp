#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int n=20;

int main() {
    int i,j,p,maxProduct = -1;
    int grid[n][n];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin >> grid[i][j];
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++) {
            //product to the right
            if(j<n-3) {
                p = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
                maxProduct = max(maxProduct, p);
            }
            //product to the bottom
            if(i<n-3) {
                p = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
                maxProduct = max(maxProduct, p);
            }
            //product of diagonal bottom right
            if(i<n-3 && j<n-3){
                p = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
                maxProduct = max(maxProduct, p);    
            }
            //product of diagonal bottom left
            if(i<n-3 && j>2) {
                p = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
                maxProduct = max(maxProduct, p);
            }
        }
    
    cout << maxProduct << endl;
    return 0;
}

// 