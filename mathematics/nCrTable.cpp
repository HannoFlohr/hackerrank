#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000000;

//https://en.wikipedia.org/wiki/Pascal%27s_triangle
int main()
{
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        ll c[n+1][n+1];
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=i; j++) {
                if(i == j || j == 0)
                    c[i][j] = 1LL;
                else 
                    c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;

                if(i==n)
                    cout << c[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/ncr-table/problem