#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;


int main() {
    uint_fast64_t max = pow(2,31);
    uint_fast64_t N, S, P, Q; 
    cin >> N >> S >> P >> Q;

    uint_fast64_t count = 1;
    uint_fast64_t prev = S % max;

    for(auto i=1; i<N; i++) {
        uint_fast64_t x = (prev * P + Q) % max;
        if(x!=prev) {
            prev = x;
            count++;
        }
        else break;
    }

    cout << count << endl;
    return 0;
}
