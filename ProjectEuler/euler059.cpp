#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, cur;
    cin >> n;
    vector<unsigned char> input;
    
    while(n--) {
        cin >> cur;
        input.push_back(cur);
    }

    for(unsigned char i='a'; i<='z'; i++) 
        for(unsigned char j='a'; j<='z'; j++) 
            for(unsigned char k='a'; k<='z'; k++) {
                //key for this iteration
                const unsigned char curKey [] = {i, j, k};

                vector<unsigned char> decoded;
                //"decode" by XORing all input values
                for(size_t pos=0; pos<input.size(); pos++) 
                    decoded.push_back(input[pos] ^ curKey[pos%3]);

                //check if result is valid
                //valid values: 0-9 a-z A-Z ; : . ' ? - ! ( ) "space"
                bool valid = true;
                for(auto d : decoded) {
                    valid = (d >= '0' && d <= '9');
                    valid |= (d>= 'a' && d <= 'z');
                    valid |= (d>= 'A' && d <= 'Z');
                    valid |= (d == '.' || d == ',' || d == '?' || d == '!'  || d == ' ');
                    valid |= (d == ';' || d == '\'' || d == '-');
                    valid |= (d == '(' || d == ')');
                    
                    if(!valid)
                        break;
                }

                if(!valid)
                    continue;

                cout << i << j << k << endl;
                return 0;
            }
        
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler059/