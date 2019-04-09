#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    //use sieve of Eratosthenes to set up primes
    int n = 1000000;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=n; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=n; i+=p) {
                prime[i] = false;
            }
        }
    }
    prime[1]=false;

    int found = 0, i = 10, check;
    int trunc [11] = {0};
    bool truncatable;
    vector<int> truncatableNumbers;
    string s;
    while(found<11 && i <=n) { 
        truncatable = true;
        
        if( prime[i] ) { 
            //check if i is truncatable from right to left
            check = i;
            while(check>0) {
                check /= 10; 
                if( !prime[check] ) {
                    truncatable = false;
                    break;
                }
            }
            if(truncatable) {            
                //check if i is truncatable from left to right
                s = to_string(i);
                while(s.length()>0) { 
                    s.erase(s.begin() ); 
                    check = atoi(s.c_str()); 
                    if( !prime[check] ) {
                        truncatable = false;
                        break;
                    }
                }
            }
            
            if(truncatable) {
                //cout << "truncatable found: " << i << endl;
                truncatableNumbers.push_back(i);
                found++;
            }
        }
        
        i++;
    }

    cin >> n;
    int sum = 0;
    for(auto a:truncatableNumbers) {
        if(a>n) break;
        sum += a;
    }
    cout << sum;
    return 0;
}
