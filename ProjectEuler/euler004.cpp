#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> palindromes;

bool isPalindrome(const int &p) {
    string s = to_string(p);
    int start = 0, end = s.size() - 1;
    while(start <= end) {
        if(s[start]!=s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void setPalindromes() {
    int product;
    for(int i=999; i>=100; i--) {
        for(int j=999; j>=100; j--) {
            product = i * j;
            if(isPalindrome(product))
                palindromes.push_back(product);
        }
    }
    sort(palindromes.rbegin(),palindromes.rend());
}

int largestPalindromeLessThan(const int &n) {
    int i=0;
    while(palindromes[i] >= n)
        i++;
    return palindromes[i];
}

int main() {
    int t,n;
    cin >> t;
        
    setPalindromes(); 
    while(t--) {
        cin >> n;
        cout << largestPalindromeLessThan(n) << endl;   
    }
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler004