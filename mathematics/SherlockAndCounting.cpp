#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
/*
i * (n-i) <= n * k
n * i - i * i <= n * k
look for case left = right and use quadratic formula u get
i = ( +/- sqrt( n^2 - 4nk) / 2 ) + n/2
need min vale -> i = n/2 - sqrt( n^2 - 4nk) / 2
result = 2 * i
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll rootof = n * n - (4 * n * k);
        
        //if the part under the sqrt is <= 0 -> all i upto n-1 are viable
        if(rootof <= 0) {
            cout << (n-1) << endl;
            continue;
        } 
        
        //i = ( n - sqrt( n^2 - 4nk) ) / 2 and result = 2 * i
        ll i = floor( ceil( sqrt(rootof) ) );
        i = (n - i)/2;
        cout << (i * 2) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/sherlock-and-counting/problem