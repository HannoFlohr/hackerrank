#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll MOD = 1000000007LL;
const int MAXN = 100001;

ll n;
ll d[MAXN][2][3];
int parents[MAXN];
bool visited[MAXN];
vector<vector<int>> graph = vector<vector<int>>(MAXN, vector<int>(0));

void DFS(int root) {
    visited[root] = true;
    for(int i=0; i<graph[root].size(); i++) {
        if(!visited[graph[root][i]]) {
            parents[graph[root][i]] = root;
            DFS(graph[root][i]);
        }
    }
}

bool isLeaf(int node) {
    for(int i=0; i<graph[node].size(); i++) {
        if(graph[node][i] != parents[node])
            return false;
    } 
    return true;
}

ll solve(int root, int color, int streak) {
    if(d[root][color][streak] != -1)
        return d[root][color][streak];
    if(isLeaf(root)) {
        if(streak == 1)
            return d[root][color][streak] = 0;
        if(streak == 2)
            return d[root][color][streak] = 1;
    }

    ll result=1, valid, invalid=1;
    int node;
    for(int i=0; i<graph[root].size(); i++) {
        if(graph[root][i] == parents[root]) continue;
        node = graph[root][i];
        valid = 0;
        valid += solve(node,!color,1);
        invalid = (invalid * solve(node,!color,1)) % MOD;
        valid += solve(node,color,2);
        result = (result * valid) % MOD;
    }

    if(streak==1)
        result = (result - invalid + MOD) % MOD;

    return d[root][color][streak] = result;
}

int main()
{
    int a,b;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<=n; i++)
        for(int j=0; j<=2; j++) {
            d[i][0][j] = -1;
            d[i][1][j] = -1;
        }

    DFS(1);

    ll result = solve(1,0,1);
    result = (result * 2LL) % MOD;
    cout << result << endl;
    return 0;
}
