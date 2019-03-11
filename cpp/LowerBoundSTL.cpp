#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned int n, x;
    vector<unsigned int> v;
    cin >> n;
    for(unsigned int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    cin >> n;
    vector<unsigned int>::iterator low;
    while(n--) {
        cin >> x;
        low = lower_bound (v.begin(), v.end(), x);
        if(v[low-v.begin()] == x ) 
            cout << "Yes ";
        else cout << "No ";
        cout << (low-v.begin())+1 << endl;
    }
    return 0;
}
