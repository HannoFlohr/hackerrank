#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef unsigned long long int ull;

//returns the count of each digit in 'number' 
ull digitCount(ull number) {
    ull digit, result = 0;
    while(number > 0) {
        digit = number % 10;
        number /= 10;
    
        //each digit can occur 2^6 = 64 times
        const ull bitsPerDigit = 6;
        result += 1ULL << (bitsPerDigit * digit);
    }
    return result;
}

int main() {
    ull N, K, cur, low;
    cin >> N >> K;
    
    map<ull,vector<ull>> permutationsCount;
    for(ull i=1; i<=N; i++) {
        cur = (ull)i*i*i;
        low = digitCount(cur);
        permutationsCount[low].push_back(i);
    }

    set<ull> validK;
    for(auto p:permutationsCount) 
        if(p.second.size() == K)
            validK.insert(p.second.front());
    
    for(auto v:validK)
        cout << (v*v*v) << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler062/