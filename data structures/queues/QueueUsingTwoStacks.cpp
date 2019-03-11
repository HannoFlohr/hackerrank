#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    stack<int> front;
    stack<int> back;

    int q, a, b;
    cin >> q;
    while(q--) {
        cin >> a;
        if(a==1) {
            cin >> b;
            back.push(b);
        }
        else {
            if(front.empty() ) {
                while(!back.empty()) {
                    front.push(back.top() );
                    back.pop();
                }
            }
            if(a==2) front.pop();
            else if(a==3) cout << front.top() << endl;
        }
    }

    return 0;
}
