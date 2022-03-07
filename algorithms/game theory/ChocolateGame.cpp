#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    unsigned long long n, cur, result=0ULL;
    //to track xor of grundy numbers for {even, odd}
    int grundy [2] = {0, 0};
    //to track how often player loses for [even,odd](grundynumber, #losses)
    map<int,int> losses_for_grundy [2];
    
    cin >> n;
    vector<unsigned> pile(n); 
    for(auto &p:pile)
        cin >> p;
    
    for(int i=0; i<n; i++) {
        //current = max removable
        if(i==0) cur = pile[i];
        else cur = pile[i] - pile[i-1];
        
        //update the odd or even grundy number
        grundy[i%2] ^= cur;
        
        //update losses for current even/odd
        losses_for_grundy[i%2][ grundy[i%2]^pile[i] ]++; 
        
        //add losses for current grundy to overall sum
        result += losses_for_grundy[i%2][ grundy[i%2] ];
        
        //update losses for other odd/even
        losses_for_grundy[(i+1)%2][ grundy[(i+1)%2] ]++;
    }
    
    cout<< (n*(n-1)/2 - result) << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/chocolate-game/problem

/* 
pile_0 <= pile_1 <= ... <= pile_n-1
diff_i = pile_i+1 - pile_i
diff_i-1 = pile_i - pile_i-1

if we remove a variable x from pile_i:
pile_i -= x -> diff_i +=x  
			   diff_i-1 -=x 
e.g. remove x from all diff_i-1 and add it to diff_i

diff with n elements is a win state if 	0 != xorsum{diff_i | 0 <= i < n and (n-1)%2==1}
*/