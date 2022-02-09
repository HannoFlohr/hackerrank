#include<bits/stdc++.h>
using namespace std;

int t,n,i;
string S;

void iterate(string s, int start) {
    if(start>=n) return;
    
    for( ; start<n; start++) {
        s += S[start];
        cout << s << endl;
        iterate(s, start+1);
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> S;    
        sort(S.begin(), S.end());
        iterate("", 0);
    }
    return 0;
}
//https://www.hackerrank.com/challenges/building-a-list/problem