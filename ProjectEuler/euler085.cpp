#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const unsigned int MAXLIMIT = 2000000;

/*
for one dimensional rectangles we get 1,3,6,10,15 for areas 1,2,3,4,5
-> Triangular numbers: https://en.wikipedia.org/wiki/Triangular_number
T(n) = n(n+1)/2

for two dimensional rectangles we can use 
T(x,y) = T(x) * T(y) (= x(x+1)/2 * y(y+1)/2 = xy(x+1)(y+1)/4)

approach:
(1) precompute triangular numbers T(n) up to MAXLIMIT
(2) compute triangular numbers for 2-dimensinal T(x,y) starting at x=1, y=1, with x<=y
    increment y until x*y exceeds the limit, greater y can't yield better results
(3) keep incrementing x and repeat
(4) x*y pair with the closest triangular number to 'target' is the result
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //precompute 1-dimensional triangular numbers
    vector<unsigned> triangularNumbers;
    for(unsigned i=0; i<=MAXLIMIT; i++) 
        triangularNumbers.push_back( i*(i+1)/2 );
    
    long int t, target, curTriangular, curArea, bestTriangular = 0, bestArea = 0;
    cin >> t;
    while(t--) {
        cin >> target;
        
        unsigned int x, y;
        //x*y<=target && x<=y -> x<=sqrt(target)
        for(x=1; x<=sqrt(target); x++) {
            y = x;
            curTriangular = 0;
            
            do {
                curTriangular = triangularNumbers[x] * triangularNumbers[y];
                curArea = x * y;
                
                if(abs(bestTriangular - target) > abs(curTriangular - target)) {
                    bestTriangular = curTriangular;
                    bestArea = curArea;
                }
                
                if(abs(bestTriangular - target) == abs(curTriangular - target) && bestArea < curArea )
                    bestArea = curArea;
                
                y++;
            } while(curTriangular < target);
        }
        
        cout << bestArea << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler085/problem