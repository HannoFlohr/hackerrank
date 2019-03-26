#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    string numbers [n];
    for(int i=0; i<n; i++)
        cin >> numbers[i];
    
    int sum = 0;
    int carry = 0;
    string result = "";
    string s = "";
    for(int i=49; i>=0; i--) {
        sum += carry;
        for(int j=0; j<n; j++)
            sum += (numbers[j][i]) - '0';
        carry = sum / 10;
        
        if(i<10) {
            s = to_string(sum);
            if(i==0) result = s + result;
            else result = s.back() + result;
        }
        
        sum = 0;
    }
    if(result.size()>10)
        result.erase(result.begin()+10, result.end());
    
    cout << result << endl;
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler013