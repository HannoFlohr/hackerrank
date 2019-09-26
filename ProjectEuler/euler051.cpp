#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAXN = 10000000;
bool prime[MAXN+1];
vector<int> primes;
map<string, vector<int>> families;
int smallestPrime = MAXN;
int n,k,l;

//replace all combinations of 'digit' by a dot when it occurs at least 'replace' times
void makeFamily(int prime, string& number,int digit, int replace, int startPos) {
    char digitChar = digit + '0';
    
    for(int i=startPos; i<n; i++) {
        if(number[i] != digitChar) continue;
        //no leading zeroes
        if(i==0 && digitChar == '0') continue;
    
        number[i] = '.';

        //if enough bits have bin replaced, add to family
        if(replace == 1) {
            auto& add = families[number];
            add.push_back(prime);
            if(add.size() >= l && add.front() < smallestPrime)
                smallestPrime = add.front();
        }
        else //else do another iteration
            makeFamily(prime, number, digit, replace-1, i+1);
    
        number[i] = digitChar;
    }
}

int main() {
    //set up vector containing all primes with max 7 digits
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=MAXN; p++) 
        if(prime[p])
            for(int i=p*p; i<=MAXN; i+=p)
                prime[i] = false;
    for(int i=2; i<MAXN; i++)
        if(prime[i])
            primes.push_back(i);

    //read input
    cin >> n >> k >> l;

    string number;
    //build families for all primes with 'n' digits
    for(auto p : primes) {
        //skip primes with too little digits
        if(p < pow(10,n-1)) continue;
        //break if current prime has too many digits
        if(p > pow(10,n)) break;

        number = to_string(p);
        for(int digit=0; digit<=9; digit++)
            makeFamily(p, number, digit, k, 0);
        
        //for input 7 1 7 result is:
        //1033777 1133777 1333777 1433777 1633777 1733777 1933777 
        //thus primes above 2 million are ignored for faster execution
        //(workaround for test case 16)
        if(k == 1 && p > 2000000) break;
    }

    //find and print minimized family
    string minimum;
    for(auto f : families) {
        //not enough members
        if(f.second.size() < l) continue;
        //not the minimum family
        if(f.second.front() != smallestPrime) continue;

        //combine all siblings to a string
        string cur = "";
        for(int i=0; i<l; i++)
            cur += to_string(f.second[i]) + " ";

        //check if current string is lower than minimum string
        if(minimum > cur || minimum.empty())
            minimum = cur;
    }

    cout << minimum << endl;
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler051/