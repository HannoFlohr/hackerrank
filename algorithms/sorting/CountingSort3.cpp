#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x;
    cin >> n;
    vector<int> a;
    string s;
    for(int i=0; i<n; i++) {
        cin >> x >> s;
        a.push_back(x);
    }

    vector<int> freq(100,0);
    for(auto i:a) freq[i]++;

    int loeq=0;
    for(auto i:freq) {
        loeq += i;
        cout << loeq << " ";
    }
    cout << endl;
    
    return 0;
}
