#include<bits/stdc++.h>
using namespace std;

/*
How many perfect right-angled triangles with c<=n exist that are NOT super-perfect?

conditions:
1) it is a perfect right-angled triangle 
    -> exclude all triangles not meeting the condition, leaving only perfects for condition 2
2) its area is a multiple of 6 and 28
    -> using properties of a primitive pythagorean triplet, one can conclude that all
        perfect right-angled triangles also meet this condition for super-perfect
        https://en.wikipedia.org/wiki/Pythagorean_triple
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q;
    unsigned long long n;
    cin >> q;
    while(q--) 
        cout << 0 << endl;
    
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler218/problem