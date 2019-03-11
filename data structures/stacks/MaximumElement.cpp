#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> main;

    int q, a,x; 
    cin >> q;
    while(q--) {
        cin >> a;
        if(a==1) {
            cin >> x;
            main.push_back(x);
        }
        else if(a==2) {
            main.pop_back();
        }
        else if(a==3) {
            auto maxpos = max_element(main.begin(),main.end());
            cout << *maxpos << endl;
        }
    }

    return 0;
}
