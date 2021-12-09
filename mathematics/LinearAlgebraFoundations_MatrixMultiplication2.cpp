#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> m1 (3);
    m1[0].push_back(1); m1[0].push_back(2); m1[0].push_back(3);
    m1[1].push_back(2); m1[1].push_back(3); m1[1].push_back(4);
    m1[2].push_back(1); m1[2].push_back(1); m1[2].push_back(1);
    
    vector<vector<int>> m2 (3);
    m2[0].push_back(4); m2[0].push_back(5); m2[0].push_back(6);
    m2[1].push_back(7); m2[1].push_back(8); m2[1].push_back(9);
    m2[2].push_back(4); m2[2].push_back(5); m2[2].push_back(7); 
    
    int rows = m1.size();
    int columns = m1[0].size();
    vector<vector<int>> result (rows, vector<int>(columns,0));
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            for(int k=0; k<rows; k++)
                result[i][j] += m1[i][k] * m2[k][j];
    
    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            cout << result[i][j] << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/linear-algebra-foundations-4-matrix-multiplication/problem?isFullScreen=true