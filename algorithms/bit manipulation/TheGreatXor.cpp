#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int BITS = 64;

/*
the xor value can only be higher at the bits where x == 0
for each such bit there are 2^bitposition numbers a that give higher xor values
*/
ll theGreatXor(ll x) {
    const string binaryX = bitset<BITS>(x).to_string();
    int bit, curbit = 0;
    while(binaryX[curbit] == '0') curbit++;
    curbit++;

    ll counter=0;
    for(int i=curbit; i<BITS; i++) {
        if(binaryX[i]=='0') {
            bit = BITS - i - 1;
            counter += (ll)pow(2LL,(ll)bit);
        }
    }

    return counter;
}

int main()
{
    int q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        cout << theGreatXor(x) << endl;
    }
    return 0;
}
