#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

/*
sum n of all numbers up to and including x: n = x(x+1)/2
2n = x(x+1)
-> valid result if sqrt(2n)*(sqrt(2n)+1)==2n 
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    ull n, root;
    cin >> t;
    while(t--) {
        cin >> n;
        root = (ull)sqrt(2*n);
        if(root * (root+1) == 2 * n)
            cout << "Go On Bob " << root << endl; 
        else
            cout << "Better Luck Next Time" << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/stepping-stones-game/problem