#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> guesses;
vector<bool> visited;
vector<int> points;
int wins;

int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b, a%b);
}

bool contains(const int &node, const int &guess) {
    for(auto i:guesses[node])
        if(i == guess) 
            return true;
    return false;
}

int DFSx(int node, int points) {
    visited[node] = true;
    for(auto i: graph[node]) {
        if(!visited[i]) {
            if( contains(node,i) ) 
                points++; 
            points += DFSx(i,0);
        }
    }
    return points;
}

void DFS(int node, const int &k) {
    if(points[node] >= k)
        wins++;
    
    for(auto i: graph[node]) {
        if(points[i] == -1) {
            if( contains(node, i) && !contains(i, node) )
                points[i] = points[node] - 1;
            else if( !contains(node, i) && contains(i, node) )
                points[i] = points[node] + 1;
            else 
                points[i] = points[node];
            DFS(i,k);
        }
    }
}

int main()
{
    int q, n, g, k, u, v;
    cin >> q;
    while(q--) {
        cin >> n;
        graph = vector<vector<int>>(n+1,vector<int>(0));
        for(int i=0; i<n-1; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cin >> g >> k;
        guesses = vector<vector<int>>(n+1, vector<int>(0));
        for(int i=0; i<g; i++) { 
            cin >> u >> v;
            guesses[u].push_back(v);
        }

        visited = vector<bool>(n+1, false);
        points = vector<int>(n+1, -1);
        points[1] = DFSx(1,0); 

        wins = 0;
        DFS(1,k);
        int div = gcd(n,wins);
        cout << (wins/div)<<"/"<<(n/div) << endl;
    }
    return 0;
}
