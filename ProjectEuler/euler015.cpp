#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int MAXSIZE = 500;

int main() {
    //precompute all possibilities using dp
    int dp [MAXSIZE+1][MAXSIZE+1];
    for(int i=0; i<=MAXSIZE; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    for(int i=1; i<=MAXSIZE; i++) {
        for(int j=1; j<=MAXSIZE; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << dp[n][m] << endl;
    }  
    return 0;
}
