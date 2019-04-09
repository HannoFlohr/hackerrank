#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll getTriangleNumber(ll n) {
    return (n * (n+1) / 2);
}

/*
tn = n * (n+1) / 2
n^2 + n = 2 * tn
-> n^2 < 2*tn
-> n < sqrt(2*tn) 
compute that n and check if it is the correct triangle number
return n or -1 if not triangle number
*/
ll getTriangleIndex(ll tn) {
    ll n = sqrt(2*tn);
    ll check = getTriangleNumber(n);
    if(tn==check)
        return n;
    else
        return -1;
}

int main() {
    ll t;
    cin>> t;
    while(t--) {
        ll tn;
        cin >> tn;
        cout << getTriangleIndex(tn) << endl;
    }
    return 0;
}
