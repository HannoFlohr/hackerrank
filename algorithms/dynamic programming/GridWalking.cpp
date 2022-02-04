#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;
int n, max_steps;
vector<int> x;
vector<int> D;

ll howManyMoves() {
    int i, j;
    ll multi_dim [max_steps+1][n+1];
    
    //for each dimenson: how many possible moves while staying in the grid for up to max_steps
    for(i=0; i<n; i++) {
        int cur_dim_max = D[i];
        ll dp [cur_dim_max+1][max_steps+1];
        
        for(j=1; j<=cur_dim_max; j++)
            dp[j][0] = 1;
            
        for(int m=1; m<=max_steps; m++) {
            for(j=1; j<=cur_dim_max; j++) {
                dp[j][m]=0;
                if(j-1 > 0)
                    dp[j][m] = (dp[j][m] + dp[j-1][m-1]) % MOD;
                if(j+1 <= cur_dim_max)
                    dp[j][m] = (dp[j][m] + dp[j+1][m-1]) % MOD;
            }
        }
        
        multi_dim[0][i+1] = 1;
        for(j=1; j<=max_steps; j++)
            multi_dim[j][i+1] = dp[x[i]][j];   
    }
    
    //nCk combinations (https://en.wikipedia.org/wiki/Binomial_coefficient)
    ll nck [max_steps+1][max_steps+1];
    for(i=0; i<=max_steps;i++) {
        nck[i][0] = 1;
        nck[i][i] = 1;
    }
    for(i=1; i<=max_steps; i++)
        for(j=1; j<i; j++)
            nck[i][j] = (nck[i-1][j-1] + nck[i-1][j]) % MOD;
    
    
    //combine result from each dimension and nCk combinations, to multi dimensions
    ll multi_dim_total [max_steps+1][n+1];
    for(i=0; i<=max_steps; i++)
        multi_dim_total[i][1] = multi_dim[i][1];
    for(i=0; i<=n; i++)
        multi_dim_total[0][i] = 1;
        
    for(i=2; i<=n; i++) {
        for(j=1; j<=max_steps; j++) {
            multi_dim_total[j][i] = 0;
            for(int k=0; k<=j; k++)
                multi_dim_total[j][i] = (multi_dim_total[j][i] + 
                                        ((nck[j][j-k] * 
                                        ((multi_dim_total[k][i-1] * multi_dim[j-k][i]) 
                                        % MOD)) % MOD)) % MOD; 
        }
    }
    
    return multi_dim_total[max_steps][n];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> max_steps;
        x = vector<int>(n);
        for(auto &i : x)
            cin >> i;
        D = vector<int>(n);
        for(auto &i : D)
            cin >> i;
            
        cout << howManyMoves() << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/grid-walking/problem