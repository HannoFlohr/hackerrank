#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;

//returns base^n % MOD
ll powMod(ll base, ll n) {
    if(n==0) 
        return 1;
    if(n==1)
        return base;
    ll halfn = powMod(base,n/2);
    if(n % 2 == 0)
        return (halfn * halfn) % MOD;
    else
        return (((halfn * halfn) % MOD) * base) % MOD; 
}

/* Looking at the combinations for different lengths of the array:
    3a + 3b
    7a + 8b + 7c
    15a + 18b + 18c + 15d
    31a + 38b + 40c + 38d + 31e
    63a + 78b + 84c + 84d + 78e + 63d
    ...
    we can see that there is a pattern to how much each element contributes 
    to the overall sum. This can be described by:
    v[0] = 2^n - 1
    v[i] = v[i-1] + 2^(y-x) - 2^x
    with x=0 and y=n-2 at start(i=1), x++ and y-- for each i 
    values for second half of contributions can be mirrored from first half,
    e.g. for length=6: contributions(a[0])=contributions(a[5])
*/
ll summingPieces(const vector<int> &a) {
    const int n = a.size();
    const int half = n / 2;
    vector<ll> contributions (n);
    contributions[0] = powMod(2,n) - 1;
    contributions[n-1] = contributions[0];
    ll x=0LL, y=n-2LL;
    ll cur;
    for(int i=1; i<=half; i++) {
        cur = powMod(2LL,y) - powMod(2LL,x);
        x++;
        y--;
        contributions[i] = (contributions[i-1] + cur) % MOD;
        contributions[i] %= MOD;
        contributions[n-1-i] = contributions[i];
    }
    //for(auto a:contributions)cout<<a<<" ";cout<<endl;
    
    ll sum = 0;
    for(int i=0; i<n; i++) {
        sum += (a[i] * contributions[i]) %MOD;
        sum %= MOD;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a (n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    cout << summingPieces(a) << endl;
    return 0;
}
