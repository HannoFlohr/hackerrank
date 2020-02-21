#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MAXN = 100001;
int n, m, x, y, w;
vector<int> parent (MAXN);
vector<int> rnk (MAXN, 1);
vector<int> child (MAXN);
vector<pair<int, pair<int,int>>> edges; // {weight,{from,to}}
vector<vector<pair<int,int>>> MST(MAXN);
bitset<MAXN> visited;
vector<ll> sum (MAXN * 4 + 100); 

int find(const int &city) {
    return parent[city] == city ? city : parent[city] = find(parent[city]);  
}

bool sameParent(const int &set1, const int &set2) {
    return find(set1) == find(set2);
}

void Union(const int &set1, const int &set2) {
    if(sameParent(set1,set2))
        return;
    
    int rank1 = find(set1);
    int rank2 = find(set2);
    if(rnk[rank1] > rnk[rank2])
        parent[rank2] = rank1;
    else 
        parent[rank1] = rank2;
        
    if(rnk[rank1] == rnk[rank2])
        rnk[rank2]++;
}

int dfs(const int &start) {
    visited[start] = 1;
    int result = 1;
    for(int i=0; i<MST[start].size(); i++) {
        if(visited[MST[start][i].second])
            continue;

        result += dfs(MST[start][i].second);
        sum[MST[start][i].first] += (ll)(n-child[MST[start][i].second]) * child[MST[start][i].second];
    }
    return child[start] = result;
}

int main()
{
    cin >> n >> m;

//"Kruskal MST"
    //start: parent of each node is itself
    for(int i=0; i<=n; i++)
        parent[i] = i;

    //read and sort edges
    for(int i=0; i<m; i++) {
        cin >> x >> y >> w;
        edges.push_back({w,{x,y}});
    }
    sort(edges.begin(), edges.end());

    //initialize MST and Union the set
    for(int i=0; i<edges.size(); i++) {
        if(sameParent(edges[i].second.first, edges[i].second.second))
            continue;

        MST[edges[i].second.first].push_back({edges[i].first, edges[i].second.second});
        MST[edges[i].second.second].push_back({edges[i].first, edges[i].second.first});
        Union(edges[i].second.first, edges[i].second.second);
    }

    //depth first search starting at node 1
    dfs(1);

    //compute bit representation of sum
    for(int i=0; i<2*m+10; i++) {
        sum[i+1] += sum[i] / 2;
        sum[i] %= 2;
    }
    
    //find most significant bit in sum 
    int msb = 2*m+10;
    while(msb>0 && sum[msb]==0)
        msb--;

    for(int i=msb; i>=0; i--)
        cout << sum[i];
    cout << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/johnland/problem