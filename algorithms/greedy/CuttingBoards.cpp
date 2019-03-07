#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;

bool compare(const pair<ll,char>& v1, const pair<ll,char>& v2) {
    return v1.first > v2.first;
}

int main()
{
    int q, m, n;
    ll x;
    cin >> q;

    while(q--) {
        cin >> m >> n;

        vector<pair<ll,char>> v;
        for(int i=0; i<m-1; i++) {
            cin >> x; 
            v.push_back( make_pair(x,'h') );
        }
        for(int i=0; i<n-1; i++) {
            cin >> x;
            v.push_back( make_pair(x,'v') );
        }
        sort(v.begin(),v.end(),compare);

        ll segments_h=1, segments_v=1, result = 0;
        for(auto a:v) {
            if(a.second=='h') {
                result += (a.first * segments_v) % MOD;
                segments_h++; 
            }
            else { 
                result += (a.first * segments_h) % MOD;
                segments_v++;
            }
            result %= MOD;
        }

        cout << result << endl;
        v.clear();
    }
    return 0;
}
