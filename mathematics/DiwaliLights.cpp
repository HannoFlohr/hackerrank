#include <bits/stdc++.h>
using namespace std;

const unsigned int MOD = 1e5;

int main()
{
    unsigned int t, n, result;
    cin >> t;
    while(t--) {
        cin >> n;

        //total number of permutations: 2^n - 1
        result = 1;
        for(unsigned int i=1; i<=n; i++) {
            result *= 2;
            result %= MOD;
        }
    
        cout << result-1 << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/diwali-lights/problem