#include <bits/stdc++.h>

using namespace std;

//count set-bits in the binary representation of n
int counterGame(unsigned long long int n) {
    int count = 0;
    while(n) {
        n &= n-1;
        count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        unsigned long long int n;
        cin >> n;
        if(counterGame(n-1) & 1) cout << "Louise" << endl;
        else cout << "Richard" << endl;
    }

    return 0;
}
