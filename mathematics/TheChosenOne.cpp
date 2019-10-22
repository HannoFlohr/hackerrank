#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

int main()
{
    ull n, maxElement, counter;
    cin >> n;
    ull v [n+1]; v[0]=0;
    for(int i=1; i<=n; i++)
        cin >> v[i];

    if(n==1) {
        cout << v[1]+1 << endl;
        return 0;
    }

    //compute gcd up to and after each element i 
    ull preGcds [n+1]; preGcds[0] = 0;
    ull postGcds [n+2]; postGcds[n+1] = 0;
    for(int i=1; i<=n; i++)
        preGcds[i] = __gcd(preGcds[i-1],v[i]);
    for(int i=n; i>=1; i--)
        postGcds[i] = __gcd(postGcds[i+1],v[i]);

    ull gcdexceptvi;
    for(int i=1; i<=n; i++) {
        gcdexceptvi = __gcd(preGcds[i-1],postGcds[i+1]);
        if(v[i] % gcdexceptvi != 0) {
            cout << gcdexceptvi << endl;
            break;
        }
    }
    return 0;
}
//https://www.hackerrank.com/challenges/the-chosen-one/problem