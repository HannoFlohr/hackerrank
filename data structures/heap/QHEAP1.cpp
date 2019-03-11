#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    priority_queue<int, vector<int>, greater<int>> heap;
    priority_queue<int, vector<int>, greater<int>> dump;

    int q,a,b;
    cin >> q;
    while(q--) {
        cin >> a;
        if(a==1){
            cin >> b;
            heap.push(b);
        }
        else if(a==2) {
            cin >> b;
            dump.push(b);
        }
        else if(a==3) {
            while(!dump.empty() && 
                    dump.top()==heap.top() ) {
                dump.pop();
                heap.pop();
            }
            cout << heap.top() <<endl;
        }

    }

    return 0;
}
