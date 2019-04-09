#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 1000000;

//returns true if 's' is palindromic
bool isPalindromic(string s) { 
    int first = 0;
    int second = s.length() - 1;
    
    while(first < second) {
        if( s[first] != s[second] ) 
            return false; 
        first++;
        second--;
    }
    return true;
}

string toOtherBase(unsigned int n, const unsigned int &base) {
    string res;
    unsigned int digit;
    while(n>0) {
        digit = n % base;
        res.insert(0, 1, char(digit + '0'));
        n /= base;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k; 

    string number;
    int sum = 0;
    for(int i=1; i<n; i++) {
        if(!isPalindromic(to_string(i)))
            continue;
        
        number = toOtherBase(i,k);
        if(isPalindromic(number))
            sum += i;
    }

    cout << sum << endl;
    return 0;
}
