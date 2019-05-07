#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    const int primes [7] = {2,3,5,7,11,13,17};

    string number = "", subString;
    for(int i=0; i<=n; i++)
        number += to_string(i);

    unsigned long long int sum = 0;
    bool dividable;
    do {
        dividable = true;
        for(int i=3; i<=n; i++) {
            subString = number.substr(i-2,3);
            if(stoi(subString) % primes[i-3] != 0) {
                dividable = false;
                break;
            }
        }

        if(dividable) sum += stoll(number);

    } while(next_permutation(number.begin(), number.end()));

    cout << sum << endl;

    return 0;
}
