#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
    Make use of following property:
    Numbers are divisible by 8 if the number formed by 
    the last three individual digits is evenly divisible by 8.
*/
int main()
{
    int t, x, size;
    bool divisible;
    string number;
    cin >> t;
    while(t--) {
        cin >> number;
        sort(number.begin(), number.end());
        divisible = false;
        size = number.size();

        do {
            if(size < 3)
                x = stoi(number);
            else 
                x = stoi( number.substr(size-3, 3) );

            if(x % 8 == 0) {
                divisible = true;
                break;
            }
        } while( next_permutation(number.begin(), number.end()) );

        cout << (divisible ? "YES" : "NO") << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/manasa-loves-maths/problem