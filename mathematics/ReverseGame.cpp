#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        
        /*  0 1 2 ... N-2 N-1 N
            after all reversals:
            N 0 N-1 1 N-2 2 ... N/2
            ball x ends at:
            if x < n/2: 2*x+1
            else (n-1-x) * 2
        */
        cout << ((k < n/2) ? (2*k+1) : ((n-1-k)*2) ) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/reverse-game/problem