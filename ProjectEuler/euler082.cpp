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
    for(unsigned i=0; i<n; i++)
        q.push( Cell(0,i,value[i][0]) );
        
    while(!q.empty()) {
        Cell c = q.top();
        q.pop();
        
        if(visited[c.y][c.x]) 
            continue;
        visited[c.y][c.x] = true; 
        
        if(c.x==n-1) 
            return c.path_sum;
        
        //go right
        if(c.x+1 < n) q.push( Cell(c.x+1, c.y, c.path_sum + value[c.y][c.x+1]));
        //go up
        if(c.y > 0) q.push( Cell(c.x, c.y-1, c.path_sum + value[c.y-1][c.x]));
        //go down
        if(c.y+1 < n) q.push( Cell(c.x, c.y+1, c.path_sum + value[c.y+1][c.x]));
    }
    
    return -1;
}

/*
first approach with a dfs search only worked for 2 test cases; time out for rest
second approach: bfs search with a priority queue, that prioritizes the Cell with smaller path_size
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
//https://www.hackerrank.com/contests/projecteuler/challenges/euler082/problem

/* First approach with dfs, passed 2 test cases, too slow for rest 

#include<bits/stdc++.h>
using namespace std;

unsigned int n, i, j;
vector<vector<unsigned>> value;
unsigned long min_end_sum = numeric_limits<unsigned long>::max();

void dfs(unsigned int x, unsigned int y, unsigned long sum, vector<vector<bool>> visited) {
    visited[x][y] = true;
    sum += value[x][y];
    
    //reached right side, check if sum less than min_end_sum
    if(y==n) {
        min_end_sum = min(min_end_sum, sum);
        return;
    }
    
    //if sum already higher than min_end_sum, abort
    if(sum >= min_end_sum) 
        return;
    
    //move up
    if(x>1 && !visited[x-1][y]) 
        dfs(x-1,y,sum,visited);
    //move down
    if(x<n && !visited[x+1][y]) 
        dfs(x+1,y,sum,visited);
    //move right
    dfs(x,y+1,sum,visited);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    value = vector<vector<unsigned>>(n+1, vector<unsigned>(n+1, 0));
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++) 
            cin >> value[i][j];
    
    vector<vector<bool>> visited (n+1,vector<bool>(n+1,false));
    dfs(2,0,0,visited);
    
    cout << min_end_sum << endl;
    return 0;
}
*/