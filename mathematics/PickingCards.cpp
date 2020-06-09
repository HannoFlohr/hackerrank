#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int MOD = 1000000007;

int main()
{
    int t, n, x, drawn, cur, i;
    ll result;
    cin >> t;
    while(t--) {
        cin >> n;

        vector<int> c (n);
        for(i=0; i<n; i++) 
            cin >> c[i];
        sort(c.begin(),c.end());

        drawn = 0; result = 1LL; i = 0;
        while(i < n) {
            cur = c[i++];
            
            if(drawn < cur) {
                result = 0;
                break;
            }
            drawn++;

            result *= (drawn - cur);
            result %= MOD;
        }
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/picking-cards/problem