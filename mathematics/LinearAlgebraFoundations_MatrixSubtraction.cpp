#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<vector<int>> m1;
    vector<vector<int>> m2;
    
    vector<int> v (3);
    v = {1,2,3};
    m1.push_back(v);
    v = {2,3,4};
    m1.push_back(v);
    v = {1, 1, 1};
    m1.push_back(v); 
    
    v = {4,5,6};
    m2.push_back(v);
    v = {7,8,9};
    m2.push_back(v);
    v = {4, 5, 0};
    m2.push_back(v); 
    
    int result = 0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cout << (m1[i][j] - m2[i][j]) << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/linear-algebra-foundations-1-matrix-subtraction/problem