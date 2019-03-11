#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<int> s; 
    int q, a, x;
    cin >> q;
    while(q--) {
        cin >> a >> x;
        if(a==1) {
            s.insert(x);
        }
        if(a==2) {
            s.erase(x);
        }
        if(a==3) {
            set<int>::iterator it = s.find(x);
            if(it==s.end()) cout << "No" << endl;
            else cout << "Yes" << endl;
        }

    }

    return 0;
}
