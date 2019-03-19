#include <bits/stdc++.h>

using namespace std;

vector<map<int,int>> adj_list;

vector<int> shortestReach(int n, int start) {
    vector<int> distance (n+1, INT_MAX);
    vector<bool> in_queue (n+1, false);
    distance[start] = 0;

    queue<int> q;
    q.push(start);
    in_queue[start] = true;
    int cur;
    while(!q.empty()) {
        cur = q.front(); q.pop();
        in_queue[cur] = false;
        for(auto a: adj_list[cur]) { 
            if(distance[a.first] > distance[cur] + a.second) {
                distance[a.first] = distance[cur] + a.second;
                if(!in_queue[a.first]) {
                    q.push(a.first);
                    in_queue[a.first] = true;
                }
            }
        }
    }

    vector<int> results;
    for(int i=1; i<=n; i++) {
        if(i==start) continue;
        if(distance[i] == INT_MAX)
            results.push_back(-1);
        else
            results.push_back(distance[i]);
    }
    return results;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t,n,e,start,x,y;
    cin >> t;
    while(t--) {
        cin >> n >> e;
        vector<vector<int>> v (e, vector<int>(3));
        for(int i=0; i<e; i++) 
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        cin >> start;

        //set adjacency list
        //for each i map all adjacent nodes to minimum weight
        adj_list = vector<map<int,int>>(n+1);
        for(auto a:v) {
            if(adj_list[a[0]][a[1]] == 0 || adj_list[a[0]][a[1]] > a[2]) 
                adj_list[a[0]][a[1]] = a[2];
            if(adj_list[a[1]][a[0]] == 0 || adj_list[a[1]][a[0]] > a[2]) 
                adj_list[a[1]][a[0]] = a[2];
        }

        vector<int> results = shortestReach(n,start);
        for(auto a:results)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
