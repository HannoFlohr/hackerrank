#include<bits/stdc++.h>
using namespace std;

const int MAXN = 50000+5;

vector<int> coins (MAXN);
vector<int> parent (MAXN, -1);
vector<int> distances (MAXN);
vector<vector<int>> adjacency (MAXN);

vector<int> odd_distances (MAXN);
vector<int> even_distances (MAXN);

//depth first search to initialize parents and distances of the graph
void dfs(int node, int curDistance, int myParent, vector<bool> &visited) {
    visited[node] = true;
    parent[node] = myParent;
    distances[node] = curDistance; 
    
    odd_distances[node] = 0;
    even_distances[node] = coins[node];
    
    for(auto a:adjacency[node]) {
        if( !visited[a] ) {
            dfs(a, curDistance+1, node, visited);
            odd_distances[node] ^= even_distances[a];
            even_distances[node] ^= odd_distances[a]; 
        }
    }
}

//returns true if node v is in the subtree of u
bool isInSubtreeOfU(int v, const int u) {
    while(v != -1) {
        v = parent[v];
        if(v == u)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //read input, set adjacency, parents and distances of graph
    int n,x,y,q,u,v,xor_sum;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> coins[i];
        
    for(int i=0; i<n-1; i++) {
        cin >> x >> y;
        x--; y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    
    vector<bool> visited (MAXN, false);
    dfs(0, 0, -1, visited);
    
    cin >> q;
    string result = "";
    while(q--) {
        cin >> u >> v;
        u--; v--;
        
        if(isInSubtreeOfU(v, u)) {
            result += "INVALID\n";
            continue;
        }
        
        xor_sum = odd_distances[0];
        
        if(distances[u]%2 == 1)
            xor_sum ^= even_distances[u];
        else 
            xor_sum ^= odd_distances[u];

        if((distances[v]+1)%2 == 1)
            xor_sum ^= even_distances[u];
        else
            xor_sum ^= odd_distances[u];
            
        result += (xor_sum == 0) ? "NO\n" : "YES\n";
    }
    
    cout << result << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/move-the-coins/problem	

/*
Similar to Staircase Nim but on tree with nodes 0...n-1 :
 
divide into nodes with even and odd distances
- if player 1 moves coins from even->odd, player 2 can move these from odd->even --> state of game doesnt change
- if player 1 moves coins from odd->even, player 2 may not be able to move (e.g. if player 1 moved coins to parent 0) 
thus only odd distance nodes are relevant
-> calculate xor sum of the odd distance nodes and the root node (xor sum odd: player 1 wins)

updating xor sum for each question:
d1 = distance between node 0 and node u
remove edge between u and parent(u) 
add edge between u and v 
d2 = new distance between node 0 and node u
- if d1%2 == d2%2 : xor sum unchanged, because odd distance nodes will still be at odd distances
- if d1%2 != d2%2 : odd distance nodes in subtree of u become even distance nodes, and all even distance nodes in subtree of u become odd distance nodes
	-> save xor sum of odd and even distance nodes seperately, and update for each question

to check if the change for each question leaves a valid tree, we can check if v is in the subtree of u
-> if true: invalid 
*/