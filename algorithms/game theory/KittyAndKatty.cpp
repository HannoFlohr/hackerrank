#include<bits/stdc++.h>
using namespace std;

/*
    whichever player gets to play the state of the game with two blocks left
    can make an optimal move to win the game for themselves
    
    special case n=1: kitty wins because only one block with value 1%3 == 1
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n == 1 || n%2 == 0)
            cout << "Kitty" << endl;
        else 
            cout << "Katty" << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/kitty-and-katty/problem