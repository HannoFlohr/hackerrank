#include<bits/stdc++.h>
using namespace std;

/*
g1: grundy numbers of piles with zero-move used
g2: grundy numbers of piles without zero-move used
g1[0]=0
g1[1]=mex{g1[0]}=1
g1[2]=mex{g1[0], g1[1]}=2
g1[3]=...=3
g1[4]=...=4
...
g2[0]=0
g2[1]=mex{g1[1], g2[0]}=2
g2[2]=mex{g1[2], g2[0], g2[1]}=1
g2[3]=...=4
g2[4]=...=3
...

-> sprague-grundy number for n is n-1 if n is even and n+1 if n is odd.
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int g, n, x, p;
    cin >> g;
    while(g--) {
        cin >> n;
        x = 0;
        
        while(n--) {
            cin >> p;
            
            if(p&1) p++;
            else p--;
            
            x ^= p;
        }
        
        cout << (x==0 ? "L" : "W") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/zero-move-nim/problem