#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n,k,u,v,d;

vector<vector<pair<int,int>>> neighbors;
vector<bool> targets;
vector<int> needed;
ll edgeSum = 0; //sum of edges that must be traversed
ll longest = 0; //longest path between two targets

//calculate longest and edgeSum using DFS
ll jeanisRoute(int cur, int prev) {
    //the (second) longest paths from this city
    //at start paths are -inf
    ll longestPath  = numeric_limits<ll>::min();
    ll secondLongestPath = numeric_limits<ll>::min();

    for(auto a:neighbors[cur]) {
        if(a.first == prev) continue;

        //find distance including all targets if travel to this city
        ll longestPathFromNeighbor = jeanisRoute(a.first, cur);
        secondLongestPath = max(secondLongestPath, longestPathFromNeighbor + a.second);

        //swap if new longest path was found
        if(secondLongestPath > longestPath) 
            swap(longestPath, secondLongestPath);
        
        needed[cur] += needed[a.first];

        //add distance of needed edge to total edge sum
        //second term cuts off starting edge if all targets are downstream
        if(needed[a.first] != 0 && needed[a.first] != k)
            edgeSum += a.second;
    }

    //if two branches lead to targets
    if(secondLongestPath > 0)
        longest = max(longest, longestPath+secondLongestPath);
    //distance from city to farthest target downstream
    if(longestPath > 0 && targets[cur])
        longest = max(longest, longestPath);

    if(targets[cur]) 
        longestPath = max(longestPath,0LL);

    return longestPath;
}

int main()
{
    cin >> n >> k;

    targets = vector<bool>(n+1,false);
    needed = vector<int>(n+1,0);
    for(int i=0; i<k; i++) {
        cin >> u;
        targets[u] = true;
        needed[u] = 1;
    }

    neighbors = vector<vector<pair<int,int>>>(n+1);
    for(int i=0; i<n-1; i++) {
        cin >> u >> v >> d;
        neighbors[u].push_back(make_pair(v,d));
        neighbors[v].push_back(make_pair(u,d));
    }

    jeanisRoute(1,1);
    cout << ((edgeSum*2) - longest) << endl;

    return 0;
}
