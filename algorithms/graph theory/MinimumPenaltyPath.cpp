#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001; //N <= 1000
const int MAXC = 1024; //C < 1024

int n, m, a, b, c, start, goal;
vector<pair<int,int>> adjacency[MAXN];

int main()
{
    cin >> n >> m;

    //set up adjacency list
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adjacency[a].push_back(make_pair(b,c));
        adjacency[b].push_back(make_pair(a,c));
    }

    cin >> start >> goal;

    bool visited[MAXN][MAXC];
    memset(visited, false, sizeof(visited));
    visited[start][0] = true;

    //BFS to check which nodes can be reached at which costs
    queue<int> q;
    q.push(start);
    queue<int> cost;
    cost.push(0);
    int cur;
    while(!q.empty()) { 
        cur = q.front();
        q.pop();
        c = cost.front();
        cost.pop();

        for(auto e : adjacency[cur]) {
            if( !visited[e.first][c | e.second] ) {
                visited[e.first][c | e.second] = true;
                q.push(e.first);
                cost.push(c | e.second);
            }
        }
    }

    //lowest cost for first visited[goal][i]=true that is encountered
    for(int i=0; i<MAXC; i++) 
        if(visited[goal][i]) {
            cout << i << endl;
            return 0;
        }

    cout << -1 << endl;

    return 0;
}

