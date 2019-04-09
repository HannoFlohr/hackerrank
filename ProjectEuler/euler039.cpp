#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef unsigned long long int ll;
const unsigned int MAXPERIMETER = 5000000; 

//returns the greatest common divisor of a and b
ll gcd(ll a, ll b) {
    while(a != 0) {
        ll c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main() {
// use Euclid's formula to generate all triplets a b c
// https://en.wikipedia.org/wiki/Pythagorean_triple
// a=k*(m^2-n^2) b=k*2mn c=k*(m^2+n^2) perimeter=a+b+c
// m and n are coprime (gcd = 1)
// m and n are not both odd
// m > n
// perimeter = ... = 2km * (m+n)
    vector<ll> countTriplets (MAXPERIMETER+1, 0);
    ll m, n, k, a, b, c, p;
    for(m=1; 2*m*m < MAXPERIMETER; m++) 
        for(n=1; n < m; n++) {
            if(m%2==1 && n%2==1) continue;
            if(gcd(m,n) > 1) continue;

            k = 1;
            while(true) {
                a = k * (m*m - n*n);
                b = k * 2 * m * n;
                c = k * (m*m + n*n);
                k++;

                p = a + b + c;
                if(p > MAXPERIMETER)
                    break;

                countTriplets[p]++;
            }
        }
    
//store the best counts 
    ll best = 0;
    set<ll> bestCount;
    bestCount.insert(0);
    for(ll i=0; i<countTriplets.size(); i++) 
        if(best < countTriplets[i]) {
            best = countTriplets[i];
            bestCount.insert(i);
        }

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        auto i = bestCount.upper_bound(n);
        i--;
        cout << *i << endl;
    } 
    return 0;
}
