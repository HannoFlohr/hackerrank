#include<bits/stdc++.h>
using namespace std;

int computeNimber(const vector<int>& nimbers, const vector<int>& neighbors) {
    int nimber = 0;
    priority_queue<int> q;
    for(int n:neighbors) {
        if(nimbers[n]==nimber) {
            nimber++;
            while(!q.empty() && -nimber == q.top()) {
                nimber++;
                while(!q.empty() && -q.top() < nimber)
                    q.pop();
            }
        }
        else if(nimbers[n] > nimber)
            q.push(-nimbers[n]);
    }
    return nimber;
}

/*
computes the nimber for position x using a dfs
nimber is the smallest integer (>=0) not equal to the nimbers of x's neighbors (see above)
*/
vector<int> dfs_for_nimbers(const vector<vector<int>>& neighbors) {
    const int size = neighbors.size();
    
    vector<int> nimbers (size,-1), index(size,0);
    vector<int> q;
    int cur, cur_neighbor_size;
    
    for(int i=0; i<size; ) {
        q.push_back(i);
        while(!q.empty()) {
            cur = q.back();
            cur_neighbor_size = neighbors[cur].size();
            
            int &j = index[cur];
            while(j != cur_neighbor_size && nimbers[neighbors[cur][j]] != -1) 
                j++;
        
            if(j == cur_neighbor_size) {
                nimbers[cur] = computeNimber(nimbers, neighbors[cur]);
                q.pop_back();
            }
            else 
                q.push_back(neighbors[cur][j++]);
        }
        
        while(i<size && nimbers[i] != -1)
            i++;
    }
    
    return nimbers;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, o, p;
    cin >> n >> m;

    vector<int> u (m), v (m);
    for(int i=0; i<m; i++) {
        cin >> o >> p;
        u[i] = --o;
        v[i] = --p;
    }
    
    vector<vector<int>> neighbors (m);
    for(int i=0; i<m; i++)
        neighbors[u[i]].push_back(v[i]); 
    
    //compute the nimbers using dfs
    vector<int> nimbers = dfs_for_nimbers(neighbors);
        
    int q, k;
    cin >> q;
    while(q--) {
        cin >> k;
        vector<int> b (k);
        for(auto& b_i:b) {
            cin >> b_i;
            b_i--;
        }
        
        int nim_sum = 0;
        for(int i:b) 
            nim_sum ^= nimbers[i];
    
        cout << (nim_sum!=0 ? "Bumi" : "Iroh") << endl;
    }
    
    return 0;
}
//https://www.hackerrank.com/challenges/benders-play/problem