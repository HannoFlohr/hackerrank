#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007; 

/*
	2^n subsets
	if i-th bit is set, than that bit will be set in the xor of half of the total subsets (=2^(n-1))
	to find all set bits in all numbers, find the OR value of all numbers
	result than is the OR value * 2^(n-1)
*/
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
		//res 1 = xor value; res2 shifted to 2^(n-1) in the loop
        long long x, res1 = 0, res2 = 1;
        cin >> n;

        for(int i=0; i<n; i++) {
            cin >> x;
            res1 |= x;
            res1 %= MOD;
            if(i > 0) {
                res2 <<= 1;
                res2 %= MOD;
            } 
        }
        cout << ((res1 * res2) % MOD) << endl;
    }
    return 0;
}
