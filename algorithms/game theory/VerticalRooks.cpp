#include<bits/stdc++.h>
using namespace std;

/* 
(columns horizontal) 1:first player 2:second player

case: _ _ _ 2 1     nimber=0    abs(3-4)-1     1 lost 
case: _ _ 2 _ 1     nimber=1    abs(2-4)-1     1 can move up to reach 2's 0 nimber condition
case: _ _ _ 1 2     nimber=0    abs(4-3)-1     1 can't make an optimal move    
case: _ _ 1 _ 2     nimber=1    abs(4-2)-1     1 can make optimal move         
case: _ 1 _ _ 2     nimber=2    abs(4-1)-1
case: 1 _ _ _ 2     nimber=3    abs(4-0)-1
...
                                abs(r2-r1)-1
XOR to compute who wins
*/
int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        
        vector<int> r1 (n), r2 (n);
        for(auto& r:r1)cin >> r;
        for(auto& r:r2)cin >> r;
        
        int winner=0;
        for(int i=0; i<n; i++)
            winner ^= abs(r2[i]-r1[i])-1;
            
        cout << (winner ? "player-2" : "player-1") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/vertical-rooks/problem