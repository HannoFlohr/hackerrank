#include<bits/stdc++.h>
using namespace std;

struct Cell {
    unsigned int x,y;
    unsigned long path_sum;
    Cell(unsigned int x_, unsigned int y_, unsigned long value_) : x(x_), y(y_), path_sum(value_) {}
    bool operator<(const Cell& cell) const { return path_sum > cell.path_sum; }
};

unsigned int n;
vector<vector<unsigned int>> value;

unsigned long bfs() {
    vector<vector<bool>> visited (n,vector<bool>(n,false));
    
    priority_queue<Cell> q;
    q.push( Cell(0,0,value[0][0]) );
        
    while(!q.empty()) {
        Cell c = q.top();
        q.pop();
        
        if(visited[c.y][c.x]) 
            continue;
        visited[c.y][c.x] = true; 
        
        if(c.x == n-1 && c.y == n-1)
            return c.path_sum;
        
        //go right
        if(c.x+1 < n) q.push( Cell(c.x+1, c.y, c.path_sum + value[c.y][c.x+1]));
        //go left
        if(c.x > 0) q.push( Cell(c.x-1, c.y, c.path_sum + value[c.y][c.x-1]));
        //go up
        if(c.y > 0) q.push( Cell(c.x, c.y-1, c.path_sum + value[c.y-1][c.x]));
        //go down
        if(c.y+1 < n) q.push( Cell(c.x, c.y+1, c.path_sum + value[c.y+1][c.x]));
    }
    
    return -1;
}

/*
slightly modified code of Project Euler+ #82
start at (0,0); finish at (n-1,n-1); and add the step down to the queue
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    value = vector<vector<unsigned>>(n, vector<unsigned>(n));
    for(unsigned i=0; i<n; i++)
        for(unsigned j=0; j<n; j++) 
            cin >> value[i][j];

    cout << bfs() << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler083/problem