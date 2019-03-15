#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;  //depth of each tree
public:
    DisjointSet(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        else
            return find(parent[i]);
    }

    bool Union(int set1, int set2) {
        if (rank[set1] > rank[set2])
            parent[set2] = set1;
        else if (rank[set1] < rank[set2])
            parent[set1] = set2;
        else {
            parent[set1] = set2;
            rank[set2]++;
        }
        return true;
    }
};

int main()
{
    int n, p;
    cin >> n >> p;

    DisjointSet ds (n);
    int a,b,root1,root2;
    for(int i=0; i<p; i++) {
        cin >> a >> b;
        root1 = ds.find(a);
        root2 = ds.find(b);
        if(root1 != root2) 
            ds.Union(root1,root2);
    }

    vector<int> frequency (n,0);
    for(int i=0; i<n; i++)
        frequency[ds.find(i)]++;

    long result=0, sum=0;
    // a*b + a*c + a*d + b*c + b*d + c*d = 
    // a*b + (a+b)*c + (a+b+c)*d
    for(auto f:frequency) {
        result += sum * f;
        sum += f;
    }
    cout << result << endl;
    return 0;
}
