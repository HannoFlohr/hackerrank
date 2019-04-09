#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    //find all primes below sqrt(987654321 = max permutation)
    set<int> smallPrimes;
    smallPrimes.insert(2);
    bool isPrime;
    for(int i=3; i*i <= 987654321; i += 2) {
        isPrime = true;
        for(auto p : smallPrimes) {
            //abort, no divisors possible
            if(p*p > i) break;
            
            //divisor found?
            if(i%p == 0) {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) smallPrimes.insert(i);
    }

    //generate all pandigital permutations for 2...9 digits
    set<int> panPrimes;
    int number;
    for(int digits=2; digits <= 9; digits++) {
        string strNumber = "123456789";
        strNumber.erase(digits);
        
        do {
            number = stoi(strNumber);
            
            isPrime = true;
            for(auto p : smallPrimes) {
                //abort, no divisors possible
                if(p*p > number) break;
                
                //divisor found? -> break
                if(number%p == 0) {
                    isPrime = false;
                    break;
                }
            }
            
            if(isPrime) panPrimes.insert(number);
        } while(next_permutation(strNumber.begin(), strNumber.end()) );
    }

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        auto i = panPrimes.upper_bound(n);
        if(i == panPrimes.begin()) {
            cout << "-1" << endl;
            continue;
        }
        i--;
        cout << *i << endl;
    }

    return 0;
}
