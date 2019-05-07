#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll solve(const vector<ll> &p) {
    ll curShares = 0, curPrize = 0, curCost = 0;
    ll result = 0;

    for(int i=p.size()-1; i>0; i--) {
        if(p[i] > p[i-1])
            curPrize = p[i]; 
        else 
            continue;

        while(i-1>=0 && p[i-1] <= curPrize) {
            curCost += p[i-1];
            i--;
            curShares++;
        }

        result += (curPrize * curShares);
        result -= curCost;
        curShares = 0;
        curPrize = 0;
        curCost = 0;
    }
    return result;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> prices (n);
        for(int i=0; i<n; i++) 
            cin >> prices[i];
        cout << solve(prices) << endl;
    }

    return 0;
}
