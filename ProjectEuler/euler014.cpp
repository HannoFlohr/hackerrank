#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned long long int ll;
const int MAXN = 5000000;

vector<ll> a (MAXN+1);

ll iterate(ll x) {
    ll temp;
    if(a[x] != 0)
        return a[x];
    
    if(x%2 == 0) {
        temp = x/2;
        a[x] = 1 + iterate(temp);
        return a[x];
    }
    else {
        temp = 3 * x + 1;
        ll count = 1;
        while(temp>MAXN+1) {
            if(temp%2==0) 
                temp /= 2;
            else 
                temp = 3 * temp + 1;
            count++;
        }
        a[x] = count + iterate(temp);
        return a[x];
    }
}

void setup() {
    ll count = 0;
    a[1] = 1;
    for(int i=2; i<=MAXN; i=i*2) {
        count++;
        a[i] = count;
    }
    for(int i=1; i<=MAXN; i++)
        iterate(i);
}

int main() {
    setup();
    
    vector<ll> results (MAXN+1);
    results[1] = 1;
    for(int i=2; i<=MAXN; i++) {
        if(a[i] >= a[results[i-1]])
            results[i] = i;
        else 
            results[i] = results[i-1];
    }
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << results[n] << endl;
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler014