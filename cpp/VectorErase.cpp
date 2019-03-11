#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,x;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }

    int pos, a, b;
    cin >> pos;
    cin >> a >> b;

    v.erase( v.begin()+pos-1 );
    v.erase( v.begin()+a-1, v.begin()+b-1 );

    cout << v.size() << endl;
    for(auto i:v) cout << i << " ";

    return 0;
}
