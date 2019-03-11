#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() { 
    int n, q;
    cin >> n >> q;

    int k [n];
    vector<int> arrays [n];
    for(int i=0; i<n; i++) {
        cin >> k[i];
        int cur;
        for(int j=0; j<k[i]; j++) {
            cin >> cur;
            arrays[i].push_back(cur);
        }
    }

    int ii, ij;
    for(int i=0; i<q; i++) {
        cin >> ii >> ij;
        cout << (arrays[ii])[ij] << endl;
    }


    return 0;
}

