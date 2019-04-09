#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int factorials [10];

bool isCuriousNumber(const int& n) {
    int factorialDigitSum = 0;
    int cur, check = n;
    while(check > 0) {
        cur = check % 10;
        factorialDigitSum += factorials[cur];
        check /= 10;
    }

    if(factorialDigitSum % n == 0)
        return true;
    else
        return false;
}

int main() {
    factorials[0] = 1;
    for(int i=1; i<10; i++) 
        factorials[i] = i * factorials[i-1];

    int n, sum = 0;
    cin >> n;

    for(int i=10; i<n; i++) {
        if(isCuriousNumber(i)) 
            sum += i;
    }
    cout << sum << endl;
    return 0;
}
