#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        int triangle[n][n] = {0};
        for(int i=0; i<n; i++) triangle[0][i] = 0;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=i; j++)
                cin >> triangle[i-1][j-1];

        int max[n][n];
        //fill lowest row with input values
        for(int i=0; i<n; i++)
            max[n-1][i] = triangle[n-1][i];
        //create max values for all cells;
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<=i; j++) {
                if(max[i+1][j] > max[i+1][j+1]) 
                    max[i][j] = triangle[i][j] + max[i+1][j];
                else 
                    max[i][j] = triangle[i][j] + max[i+1][j+1];
            }
        }

        cout << max[0][0] << endl;
    } 
    return 0;
}
