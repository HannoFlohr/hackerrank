#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/combinatorial-game-theory-set-4-sprague-grundy-theorem/

Suppose there is a composite game (more than one sub-game) made up of N sub-games and two players, A and B. Then Sprague-Grundy Theorem says that if both A and B play optimally (i.e., they don’t make any mistakes), then the player starting first is guaranteed to win if the XOR of the grundy numbers of position in each sub-games at the beginning of the game is non-zero. Otherwise, if the XOR evaluates to zero, then player A will lose definitely, no matter what.

We can apply Sprague-Grundy Theorem in any impartial game and solve it. The basic steps are listed as follows:

    Break the composite game into sub-games.
    Then for each sub-game, calculate the Grundy Number at that position.
    Then calculate the XOR of all the calculated Grundy Numbers.
    If the XOR value is non-zero, then the player who is going to make the turn (First Player) will win else he is destined to lose, no matter what.

In this case, for each forest:
Gn(0) = 0 by definition
Gn(1) = Mex(Gn(0)) = Mex(0) = 1
Gn(2) = Mex(Gn(1)) = Mex(1) = 0
Gn(3) = Mex(Gn(0),Gn(2)) = Mex(0,1) = 2
Gn(4) = Mex(Gn(0),Gn(3)) = Mex(0,2) = 1
Gn(5) = Mex(Gn(0),Gn(4)) = Mex(0,1) = 2
Gn(6) = Mex(Gn(0),Gn(5)) = Mex(0,2) = 1
-> for each forest (with more than two leaves) XOR by 1 if even number trees and by 2 if odd
*/
int main()
{
    int g, n, m, k, winner;
    cin >> g;
    while(g--) {
        cin >> n;

        winner = 0;

        for(int i=0; i<n; i++) {
            cin >> m >> k;

            if(m % 2 == 1) 
                winner ^= 1;
            else if(m > 2)
                winner ^= 2;
        }

        cout << (winner == 0 ? "BEN" : "BOB") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/bob-and-ben/problem