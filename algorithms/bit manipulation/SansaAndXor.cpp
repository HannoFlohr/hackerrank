#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

/*
identify how often each v[i] is used -> freq[i]
if freq[i] is even v[i]^v[i] = 0, so v[i] does not contribute overall
for even n, all freq[i] = 0, thus result is 0

if freq[i] is odd v[i] contributes one time to the result -> result ^= v[i]
for odd n:
i even -> freq[i] odd
i odd -> freq[i] even
thus xor v[i] for all even i
*/
ll solve(vector<ll> v) {
    int n = v.size();
    if(n % 2 == 0) 
        return 0;
    
    ll result = 0;
    for(int i=0; i<n; i+=2)
        result ^= v[i];
    return result;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v (n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        cout << solve(v) << endl;
    }
    return 0;
}
