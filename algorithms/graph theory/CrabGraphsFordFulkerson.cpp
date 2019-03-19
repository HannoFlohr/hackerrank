#include <bits/stdc++.h>

using namespace std;

int source, sink;

int residualCapacity(const vector<vector<int>> &capacity, const vector<vector<int>> &flow, const int &from, const int &to) {
    if(capacity[from][to])
        return capacity[from][to] - flow[from][to];
    else if(capacity[to][from]) 
        return flow[to][from];
    else 
        return 0;
}

// BFS for residual path
// -1 = unvisited; -2 = no parent
vector<int> findResidualPath(const vector<vector<int>> &capacity, const vector<vector<int>> &flow) {
    vector<int> parent (sink+1,-1);
    parent[source] = -2;
    
    vector<int> path;
    queue<int> q;
    q.push(source);
    int cur;
    while(!q.empty()) {
        cur = q.front(); 
        q.pop();
        for(int j=0; j<capacity.size(); j++) {
            if(parent[j] == -1) {
                if( residualCapacity(capacity,flow,cur,j) ) {
                    if(j==sink) {
                        path.push_back(sink);
                        int par = cur;
                        while(par != -2) {
                            path.push_back(par);
                            par = parent[par];
                        }
                        return path;
                    }
                    else {
                        parent[j] = cur;
                        q.push(j);
                    }
                }
            }
        }
    }
    return path;
}

//using the Ford-Fulkerson algorithm
//"Section 26.2: The Ford–Fulkerson method" - Introduction to Algorithms (CLRS)
vector<vector<int>> maxFlow(const vector<vector<int>> &capacity) {
    vector<vector<int>> flow (sink+1, vector<int>(sink+1,0));
    vector<int> path = findResidualPath(capacity, flow);
    
    int minCapacity, resCapacity;
    while(!path.empty()) {
        minCapacity = capacity.size();
        for(int i=0; i<path.size()-1; i++) {
            resCapacity = residualCapacity(capacity,flow,path[i+1],path[i]);
            if(resCapacity < minCapacity)
                minCapacity = resCapacity;
        }
        for(int i=0; i<path.size()-1; i++) {
            if(capacity[path[i+1]][path[i]])
                flow[path[i+1]][path[i]] += minCapacity;
            else 
                flow[path[i]][path[i+1]] -= minCapacity;
        }
        path = findResidualPath(capacity,flow);
    }
    return flow;
}

int solve(vector<vector<int>> &capacity) {
    vector<vector<int>> flow = maxFlow(capacity); 
    int nodes = source/2, total = 0;
    for(int i=0; i<nodes; i++)
        if(flow[source][2*i] != 0)
            total += flow[source][2*i];
    return total;
}

int main()
{
    int q;
    cin >> q;
    while(q--) {
        int n, feet, m, v1, v2;
        cin >> n >> feet >> m;

        source = 2*n; 
        sink = source+1;
        vector<vector<int>> capacity (sink+1, vector<int>(sink+1,0));
        while(m--) {
            cin >> v1 >> v2;
            v1--; v2--;
            capacity[2*v1][2*v2+1] = 1;
            capacity[2*v2][2*v1+1] = 1;
            capacity[source][2*v1]++;
            capacity[source][2*v2]++;
        }

        for(int i=0; i<n; i++) {
            capacity[2*i+1][sink] = 1;
            if(capacity[source][2*i] > feet)
                capacity[source][2*i] = feet;
        }
        cout << solve(capacity) << endl;
    }

    return 0;
}
