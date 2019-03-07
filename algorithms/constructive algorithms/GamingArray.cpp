#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g, n, cur, max, counter;
    cin >> g;
    while(g--) {
        cin >> n;

        max=0; counter=0;
        for(int i=0; i<n; i++) {
            cin >> cur;
            if(cur>max) {
                max = cur;
                counter++;
            }
        }
        if(counter%2==0) cout << "ANDY" << endl;
        else cout << "BOB" << endl;
    }
    return 0;
}
