#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {  
    int q,a,y;
    string x;
    map<string, int> m;

    cin >> q;
    while(q--) {
        cin >> a;
        if(a==1) {
            cin >> x >> y;
            m[x] += y;
        }
        else if(a==2) {
            cin >> x;
            m.erase(x);
        }
        else if(a==3) {
            cin >> x;
            cout << m[x] << endl;
        }
    }

    return 0;
}



