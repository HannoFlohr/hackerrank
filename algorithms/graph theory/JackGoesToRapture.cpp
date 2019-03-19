#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class DisjointSet {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;  //depth of each tree
public:
    DisjointSet(int n) {
        for (int i=1; i<=n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int city) {
        if (parent[city] == city)
            return city;
        else
            return find(parent[city]);
    }

    bool Union(int set1, int set2) {
        if (rank[set1] > rank[set2]) 
            parent[set2] = set1;
        else if (rank[set1] < rank[set2]) 
            parent[set1] = set2;
        else {
            parent[set1] = set2;
            rank[set2]++;
        }
        return true;
    }
};

bool compare(const vector<ll> &v1, const vector<ll> &v2) {
    return v1[2] < v2[2];
}

int main()
{
    int nodes, edges, from, to; 
    ll weight;
    cin >> nodes >> edges;

    vector<vector<ll>> edge (edges,vector<ll>(3));
    for(int i=0; i<edges; i++) 
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    sort(edge.begin(),edge.end(),compare);

    vector<ll> cost (nodes+1,numeric_limits<ll>::max());
    cost[1] = 0;

    DisjointSet ds (nodes);
    ll root1, root2, minimumCost = 0;
    for(auto e:edge) {
        root1 = ds.find(e[0]);
        root2 = ds.find(e[1]);
        if(root1 != root2) 
            ds.Union(root1,root2);
        if(ds.find(1) == ds.find(nodes)) {
            minimumCost = e[2];
            break;
        }
    }
    
    if(ds.find(1) != ds.find(nodes)) 
        cout << "NO PATH EXISTS" << endl;
    else
        cout << minimumCost << endl;

    return 0;
}
