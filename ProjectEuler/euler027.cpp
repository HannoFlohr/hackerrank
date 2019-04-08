#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//return true if number is prime
bool isPrime(int number) {
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; (i*i) <= number; i += 2)
        if (number % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    cin >> n;

    int consecutivePrimes = 0, aBest = 0, bBest = 0, curConsecutives;
    for(int a=-n; a<=n; a++)
        for(int b=0; b<=n; b++) {
            if(!isPrime(b))
                continue;
            
            curConsecutives = 0;
            while(isPrime(curConsecutives*curConsecutives + a*curConsecutives + b))
                curConsecutives++;

            if(consecutivePrimes < curConsecutives) {
                consecutivePrimes = curConsecutives;
                aBest = a;
                bBest = b;
            }
        }

    cout << aBest << " " << bBest <<endl;

    return 0;
}
