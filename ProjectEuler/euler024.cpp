#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ll;
const string start = "abcdefghijklm";
vector<ll> factorials (14); //13! is max

int main() {
    factorials[0] = 1;
    for(int i=1; i<=13; i++) 
        factorials[i] = i * factorials[i-1];

    ll t, n, fact, pos;
    cin >> t;
    while(t--) {
        cin >> n;
        n %= factorials[start.size()];
        n--;

        string result, remain = start;
        while(!remain.empty()) {
            fact = factorials[remain.size() - 1];
            pos = n / fact;

            result += remain[pos];
            remain.erase(pos,1);
            n %= fact;
        }
        cout << result << endl;
    }
    return 0;
}
