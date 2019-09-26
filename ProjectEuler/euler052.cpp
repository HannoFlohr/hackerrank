#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//returns true if 's1' and 's2' are permutations of each other
bool arePermutations(string s1, string s2) {
    int l1 = s1.length(), l2 = s2.length();
    //unequal length -> not permutations
    if(l1 != l2) 
        return false; 

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if(s1 == s2) 
        return true;
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    string result;

    for(unsigned int x=1; x<=n; x++) {
        result = to_string(x) + " ";
        //for each multiple of 'x', up to 'k*x', check if permutations
        for(unsigned int mult=2; mult<=k; mult++) {
            int xMult = x * mult;
            if(arePermutations(to_string(x), to_string(xMult))) { 
                result += to_string(xMult) + " ";
                //if this point is reached, valid result is found -> print 
                if(mult == k)
                    cout << result << endl;
            }
            else 
                break;
        }
    }

    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler052/