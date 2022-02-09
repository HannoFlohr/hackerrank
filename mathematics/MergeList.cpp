#include<bits/stdc++.h>
using namespace std;

const unsigned MOD = 1000000007;
const unsigned MAXN = 100+1;

/*
case (n=0 AND m=x) OR (n=x AND m=0) -> 1 combination
case n=1 AND m=1 -> 2 combinations
case (n=1 OR m=1) AND the other one is x -> x * 1 combinations
    e.g. n=2 m=1 -> 3 combinations

we can see a pattern as follows:
n:
0   1   1   1   1   :m
1   2   3   4   5
1   3   6   10  ..
1   4   10  20  ..
1   5   15  

for each (m,n) pair there are (m-1,n)+(m,n-1) possible combinations
-> use dp to precompute the possible combinations
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t, n, m, i, j, k;
    
    int dp [MAXN][MAXN];
    memset(dp,0,sizeof(dp));
    for(i=1; i<MAXN; i++) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
        
    for(j=1; j<MAXN; j++) 
        for(i=1; i<MAXN; i++) {
            dp[j][i] = dp[j-1][i] + dp[j][i-1];
            dp[j][i] %= MOD;
        }
        
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/merge-list/problem