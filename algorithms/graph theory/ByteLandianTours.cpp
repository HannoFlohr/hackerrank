/*
Such a tour exists only when the tree is a caterpiller tree which is a tree consisting of a straight path with some leafs attached to nodes on that path. Using this observation, getting a recurrence and solving it using Dynamic Programming is greatly simplified. Also, working out some examples on paper, it is easy to see that the answer is 2 * n1! * ... * nk! where n1,..,nk are the number of leafs attached to each node on the path defining the caterpiller tree. A special case is when the tree is a star, when the answer is simply (n - 1)!. 
See: http://en.wikipedia.org/wiki/Caterpillar_tree
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MOD = 1000000007;
const int MAXN = 10001;

vector<int> edges[MAXN];
int dp[MAXN];
bool isLeaf[MAXN];

int solve(const int &n) {
    int paths = n, result = 1, leaf, inner;

    for(int i=0; i<n; i++) 
        if(edges[i].size() == 1) {
            paths--;
            isLeaf[i] = true;
        }
    
    for(int i=0; i<n; i++) {
        if(isLeaf[i]) continue;

        leaf = 0, inner = 0;

        for(int j=0; j<edges[i].size(); j++) {
            if(isLeaf[edges[i][j]])
                leaf++;
            else 
                inner++;
        }

        if(inner > 2) return 0;

        result = 1LL * result * dp[leaf] % MOD;
    }
    
    return paths == 1 ? result : result * 2 % MOD;
}

int main()
{
    int t, n, x, y;
    cin >> t;

    dp[0] = 1;
    for(int i=1; i<MAXN; i++)
        dp[i] = 1LL * i * dp[i-1] % MOD;

    while(t--) {
        cin >> n;

        for(int i=0; i<MAXN; i++) edges[i].clear();
        memset(isLeaf, false, sizeof(isLeaf));
        
        for(int i=0; i<n-1; i++) {
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        cout << solve(n) << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/bytelandian-tours/problem