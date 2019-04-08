#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q, i;
    string query;
    cin >> n;
    vector<string> names (n);
    vector<int> values (n,0);
    
    for(i=0; i<n; i++)
        cin >> names[i];

    sort(names.begin(),names.end());

    for(i=0; i<n; i++) 
        for(auto c : names[i]) 
            values[i] += (c - 'A' + 1);
            
    cin >> q;
    while(q--) {
        cin >> query;
        i=0;
        while(names[i] != query) 
            i++;

        cout << values[i] * (i+1) << endl;
    }
    return 0;
}
