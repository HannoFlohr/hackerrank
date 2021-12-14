#include<bits/stdc++.h>
using namespace std;

const int MAXN = 501;
vector<vector<int>> tree (MAXN, vector<int>());

int dfs(int node, int parent) {
    int x=0, u;
    
    for(int i=0; i<(int)tree[node].size(); i++) {
        u = tree[node][i];
        
        if(u != parent)
            x ^= (dfs(u, node) + 1);
    }
    
    return x;
}

//http://math450games.blogspot.com/2017/02/green-hackenbush.html
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, u, v;
    cin >> t;
    while(t--) {
        cin >> n;
    
        for(int i=0; i<=n; i++)    
            tree[i].clear();
        
        for(int i=0; i<n-1; i++) {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    
        cout << (dfs(1,-1) ? "Alice" : "Bob") << endl;
    
    }
    return 0;
}
//https://www.hackerrank.com/challenges/deforestation-1/problem