#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//check if a^2 + b^2 = c^2 
bool isTriplet(const int &a, const int &b, const int &c) {
    return (a*a+b*b==c*c) ? true : false; 
}

/*
	a^2 + b^2 = c^2  &&  a+b+c=n
	-> a^2 + b^2 = (n-a-b)^2 
	-> b = (n^2 - 2na) / (2n - 2a)
*/
int solve(const int &n) {
    int a, b, c, maxProduct = -1;
    
    for(a=1; a<=n/3; a++) {
        b = (n*n - 2*n*a) / (2*n - 2*a); 
        c = n - a - b;
        if(isTriplet(a,b,c)) 
            maxProduct = max(maxProduct, a*b*c);
        
    }
    return maxProduct;
}

int main() {
    int t,n,result;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

// https://www.hackerrank.com/contests/projecteuler/challenges/euler009