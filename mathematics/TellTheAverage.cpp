#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> l (n);
    for(auto &i : l)
        cin >> i;
        
    for(int i=1; i<n; i++) {
        l[0] = l[0] + l[i] + l[0]*l[i];
        l[0] %= MOD;
    } 
    
    cout << l[0] << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/tell-the-average/problem