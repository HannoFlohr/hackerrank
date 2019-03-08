#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    map<int,int> parents;
    map<int,int> size;
    int max;
    UnionFind() {max=0;}

    void unite(int v1, int v2) {
        if(parents[v1] == 0) {
            parents[v1] = v1;
            size[v1] = 1;
        }
        if(parents[v2] == 0) {
            parents[v2] = v2;
            size[v2] = 1;
        }

        int p1=find(v1); 
        int p2=find(v2);
        if(p1==p2) return;

        int s1 = size[p1];
        int s2 = size[p2];
        if(s1<s2) {
            parents[p1] = p2;
            size[p2] = s1+s2;
            if(size[p2] > max) max = size[p2];
        }
        else {
            parents[p2] = p1;
            size[p1] = s1+s2;
            if(size[p1] > max) max = size[p1];
        }
    }

    int find(int v) {
        while( parents[v] != v ) {
            parents[v] = parents[ parents[v] ];
            v = parents[v];
        }
        return v;
    }
};

vector<int> maxCircle(vector<vector<int>> queries) {
    UnionFind uf = UnionFind();
    vector<int> results;
    for(auto q:queries) {
        uf.unite(q[0],q[1]);
        results.push_back(uf.max);
    }
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
