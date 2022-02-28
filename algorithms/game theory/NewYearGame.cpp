#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, ones, twos;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a (n);
        for(auto& i : a) {
            cin >> i;
            //only values%3 are needed for to check sums
            i %= 3;   
        }
        
        //all values are either 0, 1 or 2 -> 0's dont contribute so we can ignore them
        //count 1's and 2's
        ones = 0, twos = 0;
        for(auto i:a) {
            if(i==1) ones++;
            else if(i==2) twos++;
        }

        /*
        Koca wins if 'ones' and 'twos' are both even
        -> as the result is %3: neither ones nor twos must be 1 for Koca to win
        */
        cout << ((ones&1) | (twos&1) ? "Balsa" : "Koca") << endl;   
    }
    return 0;
}
//https://www.hackerrank.com/challenges/newyear-game/problem