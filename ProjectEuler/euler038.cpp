#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPandigital(string s, const int &k) {
    if(s.length() != k) return false;
    sort(s.begin(),s.end());
    if(k==9) return s.compare("123456789") == 0;
    else return s.compare("12345678") == 0;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s = "";
    int i=2, j=1;

    while(i<n) {
        while(s.length() < k) {
            s += to_string(i*j);
            j++;
        }

        if(s.length() == k) {
            if(isPandigital(s,k)) {
                cout << i << endl;
            }
        }

        s = "";
        i++;
        j = 1;
    }

    return 0;
}
