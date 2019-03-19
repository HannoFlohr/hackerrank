#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
vector<vector<int>> dist;

int main()
{
    int n, e, q, start, end;
    cin >> n >> e;
    vector<vector<int>> edges (e, vector<int>(3));
    for(int i=0; i<e; i++)
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    
    //use Floyd-Warshall algorithm to compute minimum distances between nodes
    //https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
    dist = vector<vector<int>>(n+1, vector<int>(n+1,INF));
    for(auto a:edges) 
        dist[a[0]][a[1]] = a[2]; 
    for(int i=1; i<=n; i++)
        dist[i][i] = 0;
    for(int k=1; k<=n; k++) 
        for(int i=1; i<=n; i++) 
            for(int j=1; j<=n; j++) 
                if(dist[i][j] > dist[i][k] + dist[k][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];

    cin >> q;
    while(q--) {
        cin >> start >> end;
        dist[start][end] == INF ? cout << -1 << endl : cout << dist[start][end] << endl;
    }

    return 0;
}
