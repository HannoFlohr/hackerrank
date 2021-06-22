#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int from; int to; int weight;
    
    bool operator<(const Edge &otherEdge) const {
        if(weight != otherEdge.weight)
            return weight > otherEdge.weight;
            
        if(from != otherEdge.from)
            return from < otherEdge.from;
            
        return to < otherEdge.to;
    }
};

set<int> nodes;
map<pair<int,int>, int> edges;

void addEdge(int from, int to, int weight) {
    if(from > to) swap(from, to);
    
    auto edge = make_pair(from, to);
    if(edges.count(edge) != 0) 
        if(edges[edge] <= weight)
            return;
            
    edges[edge] = weight;
    nodes.insert(from);
    nodes.insert(to);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, from, to, weight;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> from >> to >> weight;
        addEdge(from, to, weight);
    }
    
    for(auto i:nodes) cerr << i << " "; cerr << endl;
    
    //https://en.wikipedia.org/wiki/Prim%27s_algorithm
    
    set<Edge> optimizedGraph;
    
    set<int> finished;
    finished.insert(*nodes.begin());
    
    while(finished.size() < nodes.size()) {
        //add edges where one node is a leaf
        priority_queue<Edge> nextEdges;
        bool hasTo, hasFrom;
        for(auto e:edges) {
            auto edge = e.first;
            hasFrom = finished.count(edge.first) != 0;
            hasTo = finished.count(edge.second) != 0;
            if(hasFrom == hasTo) 
                continue;
                
            nextEdges.push({edge.first, edge.second, e.second});
        }
        
        //edge with minimal weight
        auto minimal = nextEdges.top();
        
        finished.insert(minimal.from);
        finished.insert(minimal.to);
        optimizedGraph.insert(minimal);
    }
    
    int optimizedSum = 0;
    for(auto i:optimizedGraph)
        optimizedSum += i.weight;
    
    cout << optimizedSum << endl;
    
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler107/problem