#include<bits/stdc++.h>
using namespace std;

/* STEP 1: convert the input roman string to a number
read roman backwards, accumulate value for same symbols
when encountering a symbol at i != symbol at i+1:
- if symbol is greater: add the accumulated to the number
- if sybol is less: subtract the accumulated from the number
*/
const vector<unsigned> valuesStep1 = {1, 5, 10, 50, 100, 500, 1000};
const vector<char> symbolsStep1 =    {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
map<char,unsigned> symbol_to_value;

unsigned convertRomanToNumber(string s) {
    unsigned number = 0, x, cur;
    for(int i=s.size()-1; i>=0; --i) {
        cur = symbol_to_value[ s[i] ]; 
        x = cur;
        
        while(i>0 && s[i]==s[i-1]) {
            x += cur;
            i--;
        }
        
        if(i==0)
            number += x;
        else {
            if(symbol_to_value[s[i-1]] > symbol_to_value[s[i]])
                number += x;
            else 
                number -= x;
        }   
    }
    
    return number;
}
//end STEP 1

/* STEP 2: convert the number to a correct roman
start with highest value for roman 'M' = 1000 and loop through all 13 possible values
while the number n is higher than the value for the current symbol:
subtract value from number and add symbol to the string
than go to next lower symbol
*/
const vector<unsigned> valuesStep2 = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const vector<string> symbolsStep2 =  {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

string convertNumberToRoman(unsigned int n) {
    string roman = "";
    
    unsigned i=0;
    while(n>0 && i<valuesStep2.size()) {
        while(valuesStep2[i] <= n) {
            roman += symbolsStep2[i];
            n -= valuesStep2[i];
        }
        i++;
    }
    
    return roman;
}
//end STEP 2

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //initialize the mapping for step1
    for(unsigned i=0; i<symbolsStep1.size(); i++)
        symbol_to_value[symbolsStep1[i]] = valuesStep1[i];
    
    unsigned t, number;
    string input, correct_roman;
    cin >> t;
    while(t--) {
        cin >> input;
        
        number = convertRomanToNumber(input);
        correct_roman = convertNumberToRoman(number);
        
        cout<< correct_roman << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler089/problem