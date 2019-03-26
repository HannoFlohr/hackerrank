#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, k, n, i, j;
    unsigned long long int current, maxProduct;
    string s;
    vector<unsigned long long int> factors (0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s;
        
        current = 1ULL;
        for(i=0; i<k; i++) {
            factors.push_back((unsigned long long int)(s[i]-'0'));
            current *= (unsigned long long int)(s[i]-'0');
        }
        maxProduct = current;
        
        for(i=k; i<n; i++) { 
            factors.erase(factors.begin());
            factors.push_back((unsigned long long int)(s[i]-'0'));
            
            current = 1ULL;
            for(j=0; j<k; j++)
                current *= factors[j];
            
            maxProduct = max(maxProduct, current);
        }
        
        cout << maxProduct << endl; 
     
        factors.clear();
    }
    return 0;
}

// https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem