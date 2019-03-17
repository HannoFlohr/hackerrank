#include <bits/stdc++.h>

using namespace std;

struct Less {
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const {
        return p1.second > p2.second;
    }
};

int prims(const int &n, vector<vector<int>> &edges, int start) {
    vector<vector<pair<int,int>>> e( n+1 );
    for(int i=0; i<edges.size(); i++) {
        e[edges[i][0]].push_back(make_pair(edges[i][1],edges[i][2]));
        e[edges[i][1]].push_back(make_pair(edges[i][0],edges[i][2]));
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, Less> q;

    int sum = 0, j = 1;
    vector<int> v (n+1,0);
    v[start] = 1;
    pair<int,int> next;
    while(j <= n) {
        for(int i=0; i<e[start].size(); i++)
            q.push( e[start][i] );
        
        next = q.top();
        while(v[next.first]!=0 && !q.empty()) {
            q.pop();
            next = q.top();
        }
        if(v[next.first]==1) break;

        v[next.first] = 1;
        start = next.first;
        sum += next.second;
        q.pop();
        j++;
    }

    return sum;
}

int main()
{
    int n, e, start, a, b, w;
    cin >> n >> e;
    vector<vector<int>> v (e, vector<int>(3));
    for(int i=0; i<e; i++) 
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    cin >> start;

    int result = prims(n, v, start);
    cout << result << endl;
    return 0;
}
