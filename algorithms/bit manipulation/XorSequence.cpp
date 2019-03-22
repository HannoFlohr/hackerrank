#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll xorSequence(ll n) {
    ll a = n % 8;
    if(a==0 || a==1) return n;
    if(a==2 || a==3) return 2;
    if(a==4 || a==5) return n+2;
    return 0;
}

int main()
{
    ll q,l,r;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        cout << (xorSequence(l-1)^xorSequence(r)) << endl;
    }
    return 0;
}


/*
A1 = 1
A2 = 1 ^ 2
A3 = 1 ^ 2 ^ 3
A4 = 1 ^ 2 ^ 3 ^ 4
...

Bi = A1 ^ A2 ^ ... ^ Ai
Bi = Bj ^ Aj+1 ^ Aj+2 ^ ... ^ Ai	0<=j<i

AL ^ AL+1 ^ ... ^ AR = BL-1 ^ BR

Bi pattern mod 8
n n 2 2 n+2 n+2 0 0
*/