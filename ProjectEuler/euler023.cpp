#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//const int LIMIT = 28123;
const int LIMIT = 20162; //Every integer greater than 20161 can be written as the sum of two abundant numbers
int abundant [LIMIT] = {0};

int sumOfDivisors(const int &n) {
    int sum = 0, root = sqrt(n);
    for(int i=1; i<=root; i++) 
        if(n % i == 0) { 
            if( (n / i) == i)
                sum += i;
            else {
                sum += i;
                sum += n/i;
            }
        }
    return sum - n;
}

bool checkAbundantSum(const int &n, const int &count) {
    for(int i=0; i<count; i++) 
        for(int j=0; j<count; j++) {
            if(abundant[i] + abundant[j] == n)
                return true;
            if(abundant[i] + abundant[j] > n)
                break;
        }
    return false;
}

int main() {
    int count = 0, sum, t, n;
    abundant[count++] = 12;

    for(int i=13; i<LIMIT; i++) {
        sum = sumOfDivisors(i);
        if(sum > i) 
            abundant[count++] = i;
    }

    cin >> t;
    while(t--) {
        cin >> n;
        if(n>=LIMIT) 
            cout << "YES" << endl;
        else {
            if(checkAbundantSum(n,count))
                cout << "YES" << endl;
            else   
                cout << "NO" << endl;
        }
    }

    return 0;
}
