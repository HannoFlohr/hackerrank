#include <bits/stdc++.h>
using namespace std;

// perform a breadth first search to compute distances from start node
vector<int> BFS(const int &n, const int &start, vector<vector<int>> adjacent) {
    vector<int> distances (n+1, 0);
    vector<bool> visited (n+1, false);

    int cur;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int visited_nodes = 1; 
    while(!q.empty()) {
        //all nodes were visited -> all distances are set; break
        if(visited_nodes >= n)
            break;

        cur = q.front();
        q.pop();

        //if node i was not visited yet and is not adjacent to the current node 'cur'
        //add i to the queue
        for(int i=1; i<=n; i++) {
            if(visited[i]) 
                continue; 
            if(find(adjacent[cur].begin(),adjacent[cur].end(),i) != adjacent[cur].end())
                continue;

            visited[i] = true;
            distances[i] = distances[cur] + 1;
            q.push(i);
            visited_nodes++;
        }
    }
    
    return distances;
}

int main()
{
    int t,n,m,from,to,s;
    cin >> t;

    while(t--) {
        cin >> n >> m;

        vector<vector<int>> adjacent (n+1, vector<int>(0));
        for (int i=0; i<m; i++) {
            cin >> from >> to; 
            adjacent[from].push_back(to);
            adjacent[to].push_back(from);
        }

        cin >> s;

        vector<int> distances (n+1);
        distances = BFS(n, s, adjacent);

        for(int i=1; i<=n; i++) {
            if(i==s) continue;
            cout << distances[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
