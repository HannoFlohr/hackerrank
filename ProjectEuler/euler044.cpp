#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll getPentagonalNumber(ll n) {
    return n * (3*n - 1) / 2;
}

bool isPentagonalNumber(ll y) {
    if(y<0) return false;
    
    /*
        y = x(3x-1)/2
        using the quadratic formula we get 
        x = (sqrt(24y+1)+1)/6
        
        there exists a solution if both conditions hold:
        (1) 24y+1 is a perfect square
        (2) sqrt(24y+1)+1 mod 6 = 0 -> sqrt(24y+1) = 5 mod 6
    */
    ll temp = y*24+1;
    ll root = sqrt( temp );
    return ( root*root == temp && root%6 == 5);
}

int main() {
    int n, k;
    cin >> n >> k;

    ll pentagonalNumber_n, pentagonalNumber_n_k, sum, dif;
    vector<ll> result;
    for(int i=k+1; i<=n; i++) { 
        pentagonalNumber_n = getPentagonalNumber(i);
        pentagonalNumber_n_k = getPentagonalNumber(i-k);

        sum = pentagonalNumber_n + pentagonalNumber_n_k;
        dif = pentagonalNumber_n - pentagonalNumber_n_k;

        if(isPentagonalNumber(sum) || isPentagonalNumber(dif)) 
            result.push_back(pentagonalNumber_n);
    }
    
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()), result.end());
    for(auto a:result) cout << a << endl;
    return 0;
}
