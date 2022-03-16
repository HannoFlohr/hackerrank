#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e5+10;
string s;

struct Node {
    int suffix, link, count;
    int chars [8];
} suffix_array[MAXN];

int get_suffix(int i, int x) {
    while(i-1-suffix_array[x].link < 0 || s[i-1-suffix_array[x].link] != s[i])
        x = suffix_array[x].suffix;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    suffix_array[0].suffix = 1; 
    suffix_array[0].link = 0;
    suffix_array[1].suffix = 1;
    suffix_array[1].link = -1;

    cin >> s;
    const int n = s.size();
    
    int x=1,y=2; 
    for(int i=0; i<n; i++) {
        x = get_suffix(i, x); 
        
        if( !suffix_array[x].chars[s[i]-'a'] ) {
            suffix_array[y].link = suffix_array[x].link+2;
            suffix_array[y].suffix = suffix_array[ get_suffix(i, suffix_array[x].suffix) ].chars[s[i]-'a']; 
            suffix_array[y].count = 0;
            suffix_array[x].chars[s[i]-'a'] = y++;
        }
        
        x = suffix_array[x].chars[s[i]-'a'];
        suffix_array[x].count++;
    }
    
    for(int i=y; i>=0; i--)
        suffix_array[ suffix_array[i].suffix ].count += suffix_array[i].count;
    
    long long result = 0LL;
    for(int i=2; i<y; i++) {
        int a = suffix_array[i].count; 
        result += (long long)a * (a-1) / 2;
        result %= MOD;
    }
    
    cout << result << endl; 
    return 0;
}
//https://www.hackerrank.com/challenges/palindromic-border/problem

https://en.wikipedia.org/wiki/LCP_array