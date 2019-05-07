#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

int main()
{
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> health (n);
        for(int i=0; i<n; i++)
            cin >> health[i];

        sort(health.begin(), health.end());
        
        ll p, s, max_p = 0;
        ll healthSum = 0;
        for(auto h:health)
            healthSum += h;

        for(ll eat=0; eat<n; eat++) {
            s = 1 + eat;
            p = s * healthSum;
            max_p = max(max_p, p);

            healthSum -= health[eat];
        }

        cout << max_p << endl;
    }

    return 0;
}
