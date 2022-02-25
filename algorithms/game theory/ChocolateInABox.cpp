#include<bits/stdc++.h>
using namespace std;

/*
https://en.wikipedia.org/wiki/Nim

to find all winning plays: 
- find nim-sum X of all heap sizes
- "winning strategy is to play in such a heap, reducing that heap 
   to the nim-sum of its original size with X"
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x=0;
    cin >> n;
    
    vector<int> a (n);
    for(auto& i:a) {
        cin >> i;
        x ^= i;
    }
    
    int first_wins = 0;
    for(auto i:a) 
        if((x ^ i) < i)
            first_wins++;
    
    cout << first_wins << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/chocolate-in-box/problem