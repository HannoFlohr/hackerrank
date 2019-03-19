#include <bits/stdc++.h>

using namespace std;

int solve(const int &n, const int &k) {
    int g1 = n % k;
    int g2 = k - g1;
    int sz1 = n/k+1;
    int sz2 = n/k;
    return g1 * sz1 * g2 * sz2 + g1 * (g1-1) * sz1 * sz1/2 +
                    g2 * (g2-1) * sz2 * sz2/2;
}

int main()
{
    int t,n,m;
    cin>>t;
    while(t--) {
        cin >> n >> m;
        int min = 1 , max = n, mid;
        while(min<max) {
            mid = (min+max) / 2;
            if(solve(n,mid) >= m) max = mid;
            else min = mid + 1;
        }
        cout << min << endl;
    }
    return 0;
}
