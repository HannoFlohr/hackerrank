#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long int ll;

/*
9 numbers with 1 digit -> first 9 digits
90 numbers with 2 digits -> next 2*90 digits
900 numbers with 3 digits -> next 3*900 digits
...
-> compute how many numbers have to be skipped to get to the current 'pos',
while keeping track of the next number 'start'
finally: pos -= skip; result is than string(start)[pos]
*/
ll getDigit(ll pos) {
    ll digits = 1;
    ll range = 9;
    ll start = 1;

    //skip numbers with too few digits
    ll skip = 0;
    while(skip + digits * range < pos) {
        skip += digits * range;
        digits++;
        range *= 10;
        start *= 10;
    }

    //adjust start and skip so that the highest digit of pos and skip are identical
    while(range > 9) {
        while(skip + digits * range < pos) {
            skip += digits * range;
            start += range;
        }
        range /= 10;
    }

    while(skip + digits < pos) {
        start++;
        skip += digits;
    }

    pos -= skip;
    pos--;

    string s = to_string(start);
    return s[pos] - '0';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll pos, d = 1;
        for(int i=0; i<7; i++) {
            cin >> pos;
            d *= getDigit(pos);
        }
        cout << d << endl;
    }

    return 0;
}
