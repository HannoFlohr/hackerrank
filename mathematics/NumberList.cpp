#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

/*
subarrays containing only elements e<k can be ignored
for each element e>k: can be observed that there are x*y matching subarrays
with x: distance from current element to previous element > k
and y: distance from current element to end of array a 
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    ll n, k, result, last_element;
    while(t--) {
        cin >> n >> k;
        vector<ll> a (n);
        for(auto &i : a) 
            cin >> i;
            
        result = 0;
        last_element = -1;
        
        for(ll i=0; i<n; i++) 
            if(a[i] > k) {
                result += (i - last_element) * (n - i);
                last_element = i;
            }
        
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/number-list/problem