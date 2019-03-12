#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const ll MOD = 1000000007LL;

int main()
{
    ll n, k, x;
    cin >> n >> k >> x;

    // 0: start=1!=end ; 1: start=1=end 
    vector<vector<ll>> d = vector<vector<ll>>(2, vector<ll>(n+1,0));
    d[0][2] = 1;
    d[1][2] = 0;
    for(int i=3; i<=n; i++) {
        d[0][i] = d[1][i-1] + (k-2) * d[0][i-1];
        d[1][i] = (k-1) * d[0][i-1];
        d[0][i] %= MOD;
        d[1][i] %= MOD;
    }

    if(x==1) cout << d[1][n] << endl;
    else cout << d[0][n] << endl;
    return 0;
}
