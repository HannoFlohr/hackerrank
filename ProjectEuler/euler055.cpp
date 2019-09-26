#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

//used to store ints as single digits, lowest digits first (1234 = {4, 3, 2, 1})
typedef vector<unsigned int> BigInt;
//first: int that is converged to; second: number of convergences to that int
map<BigInt,int> convergesTo;

void outBigInt(const BigInt& n) {
    for(int i=n.size()-1; i>=0; i--)
        cout << n[i];
}

//adds second to first, digit by digit
void add(BigInt& first, BigInt second) {
    unsigned int sum, carry = 0;
    for(int i=0; i<first.size(); i++) {
        sum = first[i] + second[i] + carry; 
        if(sum < 10) {
            first[i] = sum;
            carry = 0;
        }
        else {
            first[i] = sum % 10;
            carry = sum / 10;
        }

        if(i==first.size()-1 && carry > 0) {
            while(carry > 0) {
                first.push_back(carry%10);
                carry /= 10;
            }
            return;
        }
    }
}

int main() {
    int n, iterations, temp; // 100 <= n <=10^5
    cin >> n;  
     
    BigInt reverseNumber; 

    for(int i=1; i<=n; i++) { 
        temp = i;
        iterations = 0;

        //set current number as BigInt
        BigInt number;
        while(temp>0) {
            number.push_back(temp%10);
            temp /= 10;
        }
        
        while(iterations < 60) {
            reverseNumber = number;
            reverse(reverseNumber.begin(),reverseNumber.end());

            //if a palindrome is found, increment convergence count
            if(number == reverseNumber) {
                convergesTo[number]++;
                break;
            }

            //add the reverse to the number
            add(number,reverseNumber);

            iterations++;
        }
    }

    BigInt maxPalindrome;
    long long maxCount = -1;
    for(auto x:convergesTo) {
        if(x.second > maxCount) {
            maxCount = x.second;
            maxPalindrome = x.first;
        }
    }

    for(int i=maxPalindrome.size()-1; i>=0; i--)
        cout << maxPalindrome[i];
    cout << " " << maxCount << endl;

    return 0;
}
