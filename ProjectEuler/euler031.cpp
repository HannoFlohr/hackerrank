#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;

int main() {
    int t, n, coin;
    const int COINAMOUNT = 8;
    const int coins [COINAMOUNT] = {1,2,5,10,20,50,100,200};
    const int MAXN = 100000;

    //ways[i][j] is the number of ways to use any copies of
    //the first i coin values to form an unordered set
    ll ways [COINAMOUNT+1][MAXN+1] = {0};
    ways[0][0] = 1;
    for(int i=0; i<COINAMOUNT; i++) {
        coin = coins[i];
        for(int j=0; j<=MAXN; j++) {
            ways[i+1][j] = ways[i][j] + (j>=coin ? ways[i+1][j-coin] : 0);
            ways[i+1][j] %= MOD;
        }
    }

    cin >> t;
    while(t--) {
        cin >> n;
        cout << ways[COINAMOUNT][n] << endl;
    }
    return 0;
}
