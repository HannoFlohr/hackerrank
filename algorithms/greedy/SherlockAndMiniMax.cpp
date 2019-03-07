#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MAXRANGE = 1000000000;

int main()
{
    ll n,x,p,q;
    cin >> n;

    vector<ll> v(n);
    for (int i=0; i<n; i++) 
        cin >> v[i];
    sort(v.begin(),v.end());

    cin >> p >> q;
    
    ll minD, maxmin=-1, result=-1, i=0, mid; 
    if(v[0]>p)
        if(maxmin < v[0]-p) {
            maxmin = v[0] - p;
            result = p;
        }
    if(v[n-1]<q) 
        if(maxmin < q-v[n-1]) {
            maxmin = q - v[n-1];
            result = q;
        }
    for(int i=0; i<n-1; i++) {
        mid = (v[i]+v[i+1]) / 2;
        if(mid <= q && mid >= p && (mid-v[i]) > maxmin) {
            maxmin = mid - v[i];
            result = mid;
        }
        else if(mid > q && q-v[i] > maxmin ) {
            maxmin = q - v[i];
            result = q;
        }
        else if(mid < p && v[i+1]-p > maxmin) {
            maxmin = v[i+1] - p;
            result = p;
        }
    }

    cout << result << endl;
    return 0;
}
