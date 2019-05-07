#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long int ll;

bool isPentagonalNumber(ll n) {
    double pentagonalTest = (sqrt(n*24.0+1.0) + 1.0) / 6.0;
    return pentagonalTest == ((ll)pentagonalTest);
}

int main() {
    ll n;
    int a, b;
    cin >> n >> a >> b;
    
    ll triangular, hexagonal;
    if(a==3 && b==5) {
        for(ll i = 1; ; i++) {
            triangular = i * (i + 1) / 2;
            if(triangular >= n) 
                break;

            if(isPentagonalNumber(triangular))
                cout << triangular << endl;
        }
    }
    else if(a==5 && b==6) {
        for(ll i = 1; ; i++) {
            hexagonal = i * (2*i - 1);
            if(hexagonal >= n)
                break;

            if(isPentagonalNumber(hexagonal))
                cout << hexagonal << endl;
        }
    }
    else    
        cerr << "wrong input" << endl;
    
    return 0;
}
