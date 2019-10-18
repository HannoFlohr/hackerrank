#include <bits/stdc++.h>
using namespace std;

const int MOD = 1234567;

int main()
{
    int t, n, res;
    cin >> t;
    while(t--) {
        cin >> n;
        n--;
        vector<int> routes (n);
        for(int i=0; i<n; i++)
            cin >> routes[i]; 
    
        res = 1;
        for(auto r:routes) {
            res *= r;
            res %= MOD;
        }

        cout << res << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/connecting-towns/problem