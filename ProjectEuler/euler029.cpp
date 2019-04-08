#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ll;
const ll maxBasePower = 16; //2^17 > 10^5

int main() {
    ll n;
    cin >> n;

    // a^b = base^(exponent*basePower)
    // b=(2..n) -> exponent*basePower = (basePower,basePower*2,...,basePower*n)
    // store smallest basePower for each product i*j
    vector<ll> minExponent ((n+1) * maxBasePower);
    for(ll i=1; i<=maxBasePower; i++)
        for(ll j=1; j<=n; j++)
            if(minExponent[i*j] == 0)
                minExponent[i*j] = i;

    vector<ll> base (n+1, 0);

    ll repeated = 0, parent, power, exponent, reduce;
    for(ll i=2; i<=n; i++) {
        parent = base[i];
        if(parent == 0) {
            power = i * i;
            while(power <= n) {
                base[power] = i;
                power *= i;
            }
            continue;
        }

        exponent = 0;
        reduce = i;
        while(reduce > 1) {
            reduce /= parent;
            exponent++;
        }

        //count numbers encountered before current
        for(int j=2; j<=n; j++) {
            if(minExponent[j*exponent] < exponent)
                repeated++;
        }
    }

    //there exist (n-1)^2 possible combinations
    //result therefore is (n-1)^2 - duplicates
    ll res = (n-1) * (n-1);
    res -= repeated;
    cout << res << endl;
    return 0;
}
