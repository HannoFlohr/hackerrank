#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j, bit, right=0, min_max_value = numeric_limits<int>::max();
    cin >> n;
    
    vector<int> a (n);
    for(i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
  
    int bits[n][32];
    for(i=0; i<n; i++) {
        for(j=31; j>=0; j--) {
            bit = (a[i] >> j) & 1;
            bits[i][31-j] = bit;
        }
    }
    
    bool done = false;
    for(i=0; i<31; i++) {
        for(j=0; j<n-1; j++) 
            if(bits[j][i] != bits[j+1][i]) {
                right = j;
                done = true;
                break;
            }
            
        if(done) break;
    }
    
    for(i=0; i<=right; i++)
        for(j=right+1; j<n; j++)
            min_max_value = min(min_max_value, (a[i] ^ a[j]));
    
    cout << min_max_value << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/yet-another-minimax-problem/problem