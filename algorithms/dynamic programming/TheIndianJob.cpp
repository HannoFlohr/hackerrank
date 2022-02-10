#include<bits/stdc++.h>
using namespace std;

const int max_G = 1000000;
const int max_N = 100;
int n, g;

//https://en.wikipedia.org/wiki/Knapsack_problem
int knapsack(vector<int> &a) {
    int dp[n+1][g+1];
    
    for(int i=0; i<=n; i++) 
        for(int j=0; j<=g; j++) {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-a[i-1]] + a[i-1]);
        }
    
    return dp[n][g];
    //return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> g;
        vector<int> a (n);
        int sum = 0;
        for(auto &i:a) {
            cin >> i;
            sum += i;
        }
        
        if(sum > 2*g)
            cout << "NO" << endl;
        else     
            cout << ( (sum - knapsack(a) <= g) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
//https://www.hackerrank.com/challenges/the-indian-job/problem