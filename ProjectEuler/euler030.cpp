#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned int powerOfDigits(int n, int power) {
    unsigned int sum = 0;
    unsigned int rem;
    while(n%10 > 0 || n/10 > 0) { 
        rem = n%10;
        sum += pow(rem,power); 
        n/=10;
    }
    return sum; 
}

int main() {
    unsigned int power;
    cin >> power;

    unsigned int maxPower = pow(10,6);
    unsigned int sum = 0, cur;
    
    for(int i=2; i<=maxPower; i++) {
        if(i == powerOfDigits(i,power)) 
            sum += i;
    }
    cout << sum << endl;
    return 0;
}
