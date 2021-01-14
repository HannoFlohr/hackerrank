#include <bits/stdc++.h>
using namespace std;

/*
    sum up all elements in array
    half the array by taking the first i values up to sum/2
    recursively check both halfes for best score

    special case: only zeros -> n-1 score
*/

typedef long long int ll;

int getBestScore(const vector<ll> &a, ll sum) { 
    if(sum%2 == 1) return 0;
    int n = a.size(), i=0;
    ll sumFirstElements = 0LL;
    sum = ceil(double(sum) / 2.0);

    if(sum == 0) {
        //if sum is 0 but there are non-zero elements in array -> 0 possible splits
        for(int i=0; i<n; i++)
            if(a[i] != 0)
                return 0;
        //all zeroes in sum 0 array -> n-1 splits possible
        return n-1;
    }

    if(n < 2) return 0;

    while(sumFirstElements != sum && i<n) {
        sumFirstElements += a[i];
        i++;
    }

    if(i == n) return 0;

    vector<ll> leftHalf(a.begin(), a.begin() + i);
    vector<ll> rightHalf(a.begin() + i, a.end());

    return 1 + max(getBestScore(leftHalf, sum), getBestScore(rightHalf, sum));
}

int main()
{
    int t, n;
    ll sum;
    cin >> t;
    while(t--) {
        cin >> n;

        vector<ll> a (n);
        sum = 0LL;
        for(int i=0; i<n; i++) {
            cin >> a[i]; 
            sum += a[i];
        }
        
        cout << getBestScore(a, sum) << endl; 
    }

    return 0;
}
//https://www.hackerrank.com/challenges/array-splitting/problem