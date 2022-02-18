#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1000;
typedef unsigned long long int ll;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t,n,cur,remain;
    vector<vector<ll>> combinations;

    for(int i=0; i<=MAXN; i++) {
        vector<ll> combinations_ith_step (MAXN, 0);
        combinations_ith_step[0] = 1;
        for(int j=1; j<=MAXN; j++) {
            combinations_ith_step[j] = combinations_ith_step[j-1];
            
            cur = j + 1;
            if(i>=cur) {
                remain = i-cur;
                combinations_ith_step[j] += combinations[remain][j];
            }
            combinations_ith_step[j] %= MOD;
        }
        combinations.push_back(combinations_ith_step);
    }  
    
    cin >> t;
    while(t--) {
        cin >> n;
        auto result = combinations[n].back();
        result--; 
        result %= MOD;
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler076/problem