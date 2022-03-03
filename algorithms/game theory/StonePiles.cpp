#include<bits/stdc++.h>
using namespace std;

const short MAXN = 50;
vector<short> grundy (MAXN+1); 
vector<bool> viable;

//recursively check viable splits for pile with given height
void split_pile(short height, short start, short summands, short sum) {
    //found a viable split -> set it as viable
    if(summands>=2 && height==0) {
        viable[sum] = true;
        return;    
    }
    
    for(short i=start; i<=height; i++)
        split_pile(height-i, i+1, summands+1, sum^grundy[i]);
}

/* Variation of Grundy's game https://en.wikipedia.org/wiki/Grundy%27s_game
original: 
Heap size           : 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 ...
Equivalent Nim heap : 0  0  0  1  0  2  1  0  2  1  0  2  1  3  2  1  3  2  4  3  0 ...
but in this case only splits into different sizes viable

grundy numbers 
1&2 cant be split           -> g(1) = g(2) = 0;
3 can be split into (1,2)   -> g(3) = mex(g(1),g(2)) = 1
4 into (1,3)                -> g(4) = 0     // loses the game for the current player, thus 0
5 into (1,4) (2,3)          -> g(5) = mex(g(1)^g(4),g(2)^g(3)) = 2
.....

grundy numbers for this problem: 0 0 0 1 0 2 3 4 0 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
								 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 
								 39 40 41 42 43 44 45 46
-> precompute these values

result for each test is the XOR of the grundy numbers of all piles
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    short t, n, cur, result;
    
    //pre-compute the grundy numbers for 1..50
    grundy[1] = grundy[2] = 0;
    for(short i=3; i<=MAXN; i++) {
        viable.clear();
        viable = vector<bool>(MAXN+1, false);
        split_pile(i, 1, 0, 0);
        
        cur = 0;
        while(viable[cur])
            cur++;
            
        grundy[i] = cur; 
    }
    
    cin >> t;
    while(t--) {
        cin >> n;
        
        result = 0;
        while(n--) {
            cin >> cur;
            result ^= grundy[cur];
        }

        cout << (result==0 ? "BOB" : "ALICE") << endl;        
    }
    return 0;
}
//https://www.hackerrank.com/challenges/stone-piles/problem