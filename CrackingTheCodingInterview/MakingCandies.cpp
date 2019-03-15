#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

ll minimumPasses(ll m, ll w, const ll p, const ll n) {
    if(n<=p) return ceil((double)n / ((double)m*(double)w) );
    if(sqrt(m)*sqrt(w) > sqrt(n)) return 1;
    ll passes = 0, candies = 0, all, canBuy, passesWithCurMW, addPasses, minPasses = numeric_limits<ll>::max();

    while(candies < n) {
        //cout<<passes<<" | "<<candies<<" | "<<m<<" "<<w<<" | "<<minPasses<<endl;
        //skip passes until next purchase can be made
        if(candies < p) {
            addPasses = ceil(((double)p-(double)candies) / ((double)m*(double)w) );
            passes += addPasses;
            candies += m * w * addPasses;
            continue;
        }

        //purchase m/w
        if(candies >= p) {
            canBuy = candies / p;
            candies %= p;
            
            all = m + w + canBuy;
            if(m > w) {
                m = max(m, all/2);
                w = all - m;
            }
            else {
                w = max(w, all/2);
                m = all - w;
            }
        }

        candies += m * w;
        passes++; 
        passesWithCurMW=passes+ceil(((double)n-(double)candies) / ((double)m*(double)w));
        minPasses = min(minPasses, passesWithCurMW);
        if(passes > minPasses) return minPasses;
    }
    return passes;
}

int main()
{
    ll m, w, p, n;
    cin >> m >> w >> p >> n;   
    cout << minimumPasses(m,w,p,n) << endl;
    return 0;
}
