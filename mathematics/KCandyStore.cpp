#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;
const int MAXN = 1001;

//https://en.wikipedia.org/wiki/Pascal%27s_triangle
int main()
{
    //precompute all nCr values for n<1000 and k<1000
    int c[MAXN][MAXN];
    memset(c, 0, sizeof(c));
    for(int i=0; i<MAXN; i++) {
        c[i][0] = 1;
        c[i][1] = i;
        for(int j=2; j<=i; j++) 
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
    }

    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;   
    //https://en.wikipedia.org/wiki/Combination#Number_of_combinations_with_repetition  
        cout << c[n+k-1][k] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/k-candy-store/problem