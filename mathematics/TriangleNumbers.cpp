#include<bits/stdc++.h>
using namespace std;

/*
observe pattern when building triangle
                            first even:
1                           -1
1 1 1                       -1
1 2 3 2 1                   2
1 3 6 7 6 3 1               3
1 4 10 16 19 16 ..          2
1 5 15 30 45 51 45 ..       4
1 6 21 50 ..                2
1 7 28 ..                   3
...                         ...

for n>2 the first even number is at [3,2,4,2] for n%4
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,n,first_even;
    cin >> t;
    while(t--) {
        cin >> n;
        n %= 4;
        switch(n) {
            case 0 : first_even = 3; break;
            case 1 : first_even = 2; break;
            case 2 : first_even = 4; break;
            case 3 : first_even = 2; break;
            default : first_even = -1;
        }
        cout << first_even << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/triangle-numbers/problem