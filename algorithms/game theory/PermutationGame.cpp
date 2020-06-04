#include <bits/stdc++.h>
using namespace std;

int a[15];
int n;
//array for bitmasking dp; n<=15 -> size = pow(2,15)
//dp[mask] is zero if the set represented by mask is an increasing sequence
int dp[1 << 15];
int last[1 << 15];

int solve(int bits) {
    //if dp[bits] != 1 -> winner already determined
    if(dp[bits] != -1) 
        return dp[bits];

    dp[bits] = 0;

    for(int i=0; i<n; i++) 
        if(bits & (1<<i)) 
            if(solve(bits - (1<<i)) == 0) {
                dp[bits] = 1;
                break;
            }
        
    return dp[bits];
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i]; 

        dp[0] = 0;
        last[0] = 0;
        
        //set initial bitmask in dp
        for(int i=0; i<n; i++) {
            for(int j=0; j<(1<<i); j++) {
                if(dp[j] == 0 && a[i] > last[j])
                    dp[j+(1<<i)] = 0;
                else
                    dp[j+(1<<i)] = -1;

                last[j+(1<<i)] = a[i]; 
            }
        }

        cout << (solve((1<<n)-1) ? "Alice" : "Bob") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/permutation-game/problem