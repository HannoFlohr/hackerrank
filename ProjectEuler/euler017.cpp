#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string getWord(int n) {
    switch(n) {
        case 1 : return "One ";
        case 2 : return "Two ";
        case 3 : return "Three ";
        case 4 : return "Four ";
        case 5 : return "Five ";
        case 6 : return "Six ";
        case 7 : return "Seven ";
        case 8 : return "Eight ";
        case 9 : return "Nine ";
        case 10 : return "Ten ";
        case 11 : return "Eleven ";
        case 12 : return "Twelve ";
        case 13 : return "Thirteen ";
        case 14 : return "Fourteen ";
        case 15 : return "Fifteen ";
        case 16 : return "Sixteen ";
        case 17 : return "Seventeen ";
        case 18 : return "Eighteen ";
        case 19 : return "Nineteen ";
        case 20 : return "Twenty ";
        case 30 : return "Thirty ";
        case 40 : return "Forty ";
        case 50 : return "Fifty ";
        case 60 : return "Sixty ";
        case 70 : return "Seventy ";
        case 80 : return "Eighty ";
        case 90 : return "Ninety ";
    }
    return "";
}

string writeOut(long long n) {
    long long helper;
    string number = "";
    if(n>=100) {
        helper = n / 100;
        number += getWord(helper) + "Hundred ";
        n = n % 100; 
    }
    if(n%10 == 0 || n<=20) {
        number += getWord(n);
    }
    else {
        helper = n % 10;
        n = n - helper;
        number += getWord(n) + getWord(helper); 
    }
    return number;
}

int main() {
    int t;
    long long x, helper;
    string res;
    cin >> t;
    while(t--) {
        cin >> x;
        res = "";

        if(x > 1000000000000) {
            res += writeOut(x/1000000000000);
            res += "Trillion ";
            x %= 1000000000000;
        }
        if(x > 1000000000) {
            res += writeOut(x/1000000000);
            res += "Billion ";
            x %= 1000000000;
        }
        if(x > 1000000) {
            res += writeOut(x/1000000);
            res += "Million ";
            x %= 1000000;
        }
        if(x > 1000) {
            res += writeOut(x/1000);
            res += "Thousand ";
            x %= 1000;
        }
        res += writeOut(x);
        cout << res << endl;
    } 
    return 0;
}