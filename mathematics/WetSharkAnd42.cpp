#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
typedef unsigned long long int ull;

ull solve(ull s) {
    if( s%20 != 0)
        return ((s/20) * 42 + (s%20) * 2) % MOD;
        
    return ((s/20) * 42 - 2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    ull s;
    cin >> t;
    while(t--) {
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/wet-shark-and-42/problem