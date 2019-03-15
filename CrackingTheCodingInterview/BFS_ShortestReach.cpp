#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    int id;
    int depth;
    vector<Node*> children;
    Node(int id) {
        this->id = id;
        children = vector<Node*>();
    }
};

class Graph {
    vector<Node*> nodes;
    public:
        Graph(int n) {
            nodes = vector<Node*>(n+1,NULL);
            for(int i=1; i<=n; i++)
                nodes[i] = new Node(i);
        }
    
        void add_edge(int u, int v) {
            nodes[u]->children.push_back( nodes[v] );
            nodes[v]->children.push_back( nodes[u] );
        }
    
        void bfs(Node* root) {
            bool visited [nodes.size()+1] = {false};
            root->depth = 0;
            visited[root->id] = true;

            queue<Node*> q;
            q.push(root);
            Node* n;
            while(!q.empty()) {
                n = q.front(); 
                q.pop();
                for(int i=0; i<n->children.size(); i++) {
                    if(visited[ n->children[i]->id ]) continue;
                    n->children[i]->depth = n->depth + 6;
                    q.push( n->children[i] );
                    visited[ n->children[i]->id ] = true;
                }
            }
        }

        vector<int> shortest_reach(int start) { 
            for(int i=1; i<nodes.size(); i++) nodes[i]->depth = -1;
            bfs(nodes[start]);
            vector<int> results;
            for(int i=1; i<nodes.size(); i++) {
                if(i == start) continue; 
                results.push_back(nodes[i]->depth); 
            }
            return results;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            // add each edge to the graph
            graph.add_edge(u, v);
        } 
		int startId;
        cin >> startId;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
                cout << distances[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

