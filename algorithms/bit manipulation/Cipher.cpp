#include <bits/stdc++.h>
using namespace std;

/*
for k=4:
v0 = s0
v1 = s0 ^ s1
v2 = s1 ^ s2
v3 = s2 ^ s3
v4 = v0 ^ s3 ^ s4
v5 = v1 ^ s4 ^ s5
...
v[n] = v[n-k] ^ s[n-1] ^ s[n]

*/
string cipher(int k, string s) { 
    int xorValue, start, n = s.size() - k + 1;
    vector<int> v (n);
    vector<int> a (n);
    for(int i=0; i<n; i++) {
        a[i] = s[i]-'0';
        if(i==0)
            v[i] = a[i];
        else if(i<k) 
            v[i] = a[i-1] ^ a[i];
        else 
            v[i] = v[i-k] ^ a[i-1] ^ a[i];
    }

    string msg = "";
    for(int i=0; i<n; i++) 
        msg += v[i] + '0';
    return msg;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << cipher(k,s) << endl;
    return 0;
}
