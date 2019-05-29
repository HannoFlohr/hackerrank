#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2001; // m <= 2 * 10^3
const int MAXK = 1025; // 1 << 10 (=max amount of fish) = 1024

class Node {
public:
    int id, cost, fish;
    Node() {}
    Node(int id, int cost, int fish) : id(id), cost(cost), fish(fish) {}
};

int n, m, k;
int fish[MAXM], dist[MAXM][MAXK];
vector<pair<int,int>> adjacency[MAXM];

void dijkstra() {
    queue<Node> q;
    q.push( Node(1,0,fish[1]) );
    Node cur, next;
    while( !q.empty() ) {
        cur = q.front();
        q.pop();

        for(auto edge : adjacency[cur.id]) {
            next = Node(edge.first, cur.cost+edge.second, cur.fish | fish[edge.first]);
        
            if(next.cost < dist[next.id][next.fish]) {
                dist[next.id][next.fish] = next.cost; 
                q.push(next);
            }
        } 
    }
}

int main()
{
    //initialize
    memset(fish, 0, sizeof(fish));
    for(int i=0; i<MAXM; i++) 
        for(int j=0; j<MAXK; j++)
            dist[i][j] = numeric_limits<int>::max();

    cin >> n >> m >> k;

    int a,b;
    //set up list of fish using bit masking
    for(int i=1; i<=n; i++) {
        cin >> a;
        for(int j=0; j<a; j++) {
            cin >> b;
            fish[i] |= (1 << (b-1));
        }
    }

    int u,v,w;
    //set up adjacency of the graph
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        adjacency[u].push_back(make_pair(v,w));
        adjacency[v].push_back(make_pair(u,w));
    }

    //solve using dijkstra algorithm
    dijkstra();

    int mask = (1 << k) - 1;
    //find minimal amount of time for the computed distances
    int result = dist[n][mask];
    for(int i=1; i<mask; i++)
        for(int j=1; j<mask; j++)
            if((i|j) == mask) 
                result = min( max(dist[n][i], dist[n][j]), result );

    cout << result << endl;

    return 0;
}
