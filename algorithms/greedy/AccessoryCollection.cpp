#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

/*
divide set L into three subsets
- L_max: count of accessory with maximal cost A
- L_mid: count of accessories with cost < A but > cost of L_end
- L_end: count of accessory with least possible cost
-> 0 <= l_end <= L_mid <= L_max <= A

maximum for L_mid = (N-1)/(D-1)
check from this maximum to 1, find L_max and L_end accordingly 
account for maximum cost
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t, l, a, n, d, sum, cur_sum, l_max, l_end, count;
    cin >> t;
    while(t--) {
        cin >> l >> a >> n >> d;
        
        //no solution if less items A than distinct items needed  
        if(a<d) {
            cout << "SAD" << endl;
            continue;
        }
        
        //every item L can be the same
        if(d==1) {
            cout << l*a << endl;
            continue;
        }
        
        sum = -1LL;
        for(ll l_mid = (n-1)/(d-1); l_mid>=1; l_mid--) { 
			//l_max is l_mid + the left out positions in subset N after assigning positions 
			//in decreasing order; one position is left out for the Nth distinct accessory
            l_max = l_mid + (n - l_mid * (d-1)) - 1; 
            l_end = (l - l_max) % l_mid; 
			//types of accessories required in l_mid
            count = (l - l_max) / l_mid;                    
            
            //not enough types available, break;
            if(count > a-1 || (count == a-1 && l_end > 0))
                break; 
            
			//sum for current iteration: 
			//amount of Ath accessory + sum of accessories in l_mid + value of lats possible accessory
            cur_sum = l_max * a + count * (a-1+a-count) * l_mid/2 + l_end * (a-count-1);
            
            //maximum sum already reached
            if(cur_sum < sum) 
                break;
            
            sum = cur_sum;
        }
        
        if(sum == -1LL) cout << "SAD" << endl;
        else cout << sum << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/accessory-collection/problem