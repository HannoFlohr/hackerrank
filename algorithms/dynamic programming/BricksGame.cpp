#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> bricks (n);
        for(int i=0; i<n; i++) 
            cin >> bricks[i];
        
        vector<ll> dp (n,-1);
        ll sum = 0;

        int i = n-1;
        //case #bricks == 1-3
        for(; i>n-4 && i>=0; i--) {
            sum += bricks[i];
            dp[i] = sum;
        }
    
        //more than 3 bricks
        while(i>=0) {
            sum += bricks[i]; 
            //give the other player the minimum possible sum
            dp[i] = max(sum - dp[i+1], max(sum - dp[i+2], sum - dp[i+3])  );
            i--;
        }
    
        cout << dp[0] << endl;
    }

    return 0;
}
