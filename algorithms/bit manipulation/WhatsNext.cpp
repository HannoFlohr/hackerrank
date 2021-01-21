#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int t, n;

void whatsNext(vector<ll> &v) {
    if(n<=2) { //workaround for corner cases
        n += 2;
        v.insert(v.begin(), 1);
        v.insert(v.begin(), 0);
    }
    
    //index of last zero in array
    ll lzi = (n&1) ? (n-2) : (n-3);
    
    if(lzi > 0) {
        ll ones = v[lzi+1];
        ll digits = ones + ((n&1) ? 0 : v[lzi+2]);
        v[lzi]--;
        v.insert(v.begin()+lzi+1, 1);
        
        if(n&1)
            v.insert(v.begin()+lzi+2, 1);
            
        v[lzi+3] = ones - 1;
        v[lzi+2] = digits - v[lzi+3];
    }
    
    if(v[0]==0 && v[1]==0) { //revert workaround
        v.erase(v.begin(), v.begin()+2);
        lzi = 0;
    }

    auto index = v.begin() + lzi;
    for( ; index<v.end(); index++) {
        if(*index==0 && index>v.begin() && index<v.end()-1) {
            v[lzi-1] += v[lzi+1];
            v.erase(index, index+2);
        }
        else if(*index==0 && index==v.end()-1)
            v.erase(index, index+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<ll> v (n);
        for(int i=0; i<n; i++) 
            cin >> v[i];
        
        whatsNext(v);
        
        cout << v.size() << endl;
        for(auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/whats-next/problem