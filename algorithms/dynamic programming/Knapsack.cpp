#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &a, const int &k) {
    // if k is a multiple of one of the values return k
    for(int i=0; i<a.size(); i++) {
        if(k % a[i] == 0) 
            return k;
    }

    // use dp to compute the closest possible value for each number < k
    int dp [k+1] = {0};
    int cur;
    for(int i=0; i<=k; i++) {
        cur = dp[i];
        for(int j=0; j<a.size(); j++) {
            if(i >= a[j]) {
                cur = max(cur, dp[ i - a[j] ] + a[j]);
            }
        }
        dp[i] = cur;
        //for(auto a:dp) cout<<a<<" ";cout<<endl;
    }

    return dp[k];
}

int main()
{
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> a (n);
        for(int i=0; i<n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());
        a.erase( unique(a.begin(),a.end()), a.end() );

        cout << solve(a, k) << endl;
    }

    return 0;
}