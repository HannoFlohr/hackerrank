#include<bits/stdc++.h>
using namespace std;

/*
    n                1   2   3   4   5   6   7   8   9   ...
    (2**n)%17        2   4   8   16  15  13  9   1   2   ...
    (-2**n)%17       15  13  9   1   2   4   8   16  15  ...
    -> repeating pattern for every 8 numbers
    
    if n is multiple of 8, P2 can always choose a number to cancel out P1s move, returning the total % 17 to 0
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        (n%8) ? cout << "First\n" : cout << "Second\n";
    }
    return 0;
}
//https://www.hackerrank.com/challenges/powers-game-1/problem?isFullScreen=true