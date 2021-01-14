#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

/*
whole set: S
d_ij = distance between set I and set J
d_ii = distance within set I
-> d_ss = d_ii + d_jj + d_ij is fixed for a given set S
-> find maximum d_ii + d_jj

assume smallest number 'a' is in I
smallest number in J is 'b'
if we switch a and b, how does d_ii+d_jj change? 
depends on relative position in sets
    d_ab = abs(a-b) 
    d_ii decreases by d_ab * (k-1) (=x), because distance between a and all other in set I decreases by d_ab
    d_jj increases by d_ab * (m-1) (=y), because distance between b and all other in set J increases by d_ab

    if(x<y) d_ii+d_jj increases, so a should be switched to set J

iterate through all numbers in array until set I has k members
*/

int main()
{
    // n: size of array; k: # of int in I; m: # of int in J
    ll n, k, m, i, j, p, sum=0;
    cin >> n >> k;
    m = n - k;

    vector<ll> a (n);
    for(i=0; i<n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    // compute "weight":
    //for each position p in set I or J: x=numbers before p; y=numbers after p
    //weight = y-x -> w[r] = y-x
    vector<ll> w1(k), w2(m);
    for(i=0; i<k; i++)
        w1[i] = k-1 - 2*i;
    for(i=0; i<m; i++)
        w2[i] = m-1 - 2*i;

    //iterate through array to build sets I and J with minimal distance
    vector<ll> I, J;
    i=0; j=0; p=0;
    while(i<k && j<m) {
        if(w1[i] > w2[j]) {
            I.push_back(a[p]);
            i++;
        }
        else {
            J.push_back(a[p]);
            j++;
        }
        p++;
    }

    //add remaining elements to sets
    if(i==k) 
        while(p<n)
            J.push_back(a[p++]);
    if(j==m)
        while(p<n)
            I.push_back(a[p++]);

    //compute sum
    for(auto i : I)
        for(auto j : J)
            sum += abs(i-j);

    cout << sum << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/fair-cut/problem