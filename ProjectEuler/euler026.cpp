#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

/*When does the fractional part repeat ?
Let us simulate the process of converting fraction to decimal. Let us look at the part 
where we have already figured out the integer part which is floor(numerator/denominator). 
Now we are left with ( remainder = numerator%denominator ) / denominator.
If you remember the process of converting to decimal, at each step we do the following :
    Multiply the remainder by 10.
    Append remainder / denominator to result.
    Remainder = remainder % denominator.
At any moment, if remainder becomes 0, we are done.

However, when there is a recurring sequence, remainder never becomes 0. For example if you look at 1/3, the remainder never becomes 0.

Below is one important observation :
If we start with remainder ‘rem’ and if the remainder repeats at any point of time, the 
digits between the two occurrence of ‘rem’ keep repeating.
*/

const unsigned int maxDenominator = 10000;

unsigned int cycleLength(unsigned int n) {
    if(n == 0) return 0;

    vector<unsigned int> lastPos(n,0);
    unsigned int pos = 1, div = 1, remainder;

    while(true) {
        remainder = div % n;
        //if remainder becomes 0, there is no cycle
        if(remainder == 0) 
            return 0;
        
        //if the same remainder occurs, return length of the cycle
        if(lastPos[remainder] != 0)
            return pos - lastPos[remainder];

        //remember position of current remainder;
        lastPos[remainder] = pos;

        pos++;
        div = remainder * 10;
    }
}

int main() {
    vector<unsigned int> results = {0};
    unsigned int longestDenominator = 0, longestCycle = 0, curCycle;
    for(unsigned int d = 1; d<=maxDenominator; d++) {
        curCycle = cycleLength(d);
        if(longestCycle < curCycle) {
            longestCycle = curCycle;
            longestDenominator = d;
        }
        results.push_back(longestDenominator);
    }

    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << results[n-1] << endl;
    }  
    return 0;
}
