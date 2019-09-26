#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned long long int ull;

//returns (a * b) % mod
ull mulMod(ull a, ull b, ull mod) {
    //using optimzed gcc extension for 128bit integers
    return ((unsigned __int128)a * b) % mod;
}

//returns (base^exp) % mod
ull powMod(ull base, ull exp, ull mod) {
    ull result = 1;
    while(exp > 0) {
        //odd exponent a^b = a*a^(b-1)
        if(exp & 1) 
            result = mulMod(result, base, mod);
        //even exponent a^b = (a*a)^(b/2)
        base = mulMod(base, base, mod);
        exp >>= 1;
    } 
    return result;
}

//Miller-Rabin test
bool millerRabin(ull p) {
//trivial cases
    const unsigned int bitmaskPrimes2to31 = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 29) | (1 << 23) |(1 << 29);
    //check if p is one of the small primes
    if(p < 31) 
        return (bitmaskPrimes2to31 & (1 << p)) != 0;
    //filter all composite number < 17*19
    if(p%2==0 || p%3==0 || p%5==0 || p%7==0 || p%11==0 || p%13==0 || p%17==0) 
        return false;
    //all others < 17*19 are prime
    if(p < 17*19)
        return true;

    //bases/"witnesses" to test p against (miller-rabin.appspot.com)
    //first three good up to 2^32
    const unsigned int STOP = 0;
    const unsigned int test1 [] = {377687, STOP};
    const unsigned int test2 [] = {31, 73, STOP};
    const unsigned int test3 [] = {2, 7, 61, STOP};
    const unsigned int test4 [] = {2, 13, 23, 1662803, STOP};
    //good up to 2^64
    const unsigned int test7 [] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022, STOP}; 

    const unsigned int* test = test7;
    //use less tests for smaller p
    if(p<5329) test = test1;
    else if(p<9080191) test = test2;
    else if(p<4759123141ULL) test = test3;
    else if(p<1122004669633ULL) test = test4;

    //find p-1 = d * 2^j
    auto d = p-1;
    d >>= 1;
    unsigned int shift = 0;
    while((d & 1) == 0) {
        shift++;
        d >>= 1;
    }

    //test p against the bases
    do {
        auto x = powMod(*test++, d, p);
        if(x==1 || x==p-1)
            continue;

        //now prime or strong pseudo-prime
        // test^(d*2^r); 0<=r<shift
        bool maybePrime = false;
        for(unsigned int r=0; r<shift; r++) {
            // x = x^2 % p
            x = powMod(x, 2, p);
            // x % p == 1 -> not prime
            if(x==1) 
                return false;

            //even larger chance to be prime
            if(x==p-1) {
                maybePrime = true;
                break;
            }
        }

        if(!maybePrime) //=not prime
            return false;
    } while(*test != STOP);

    return true;
}

int main() {
    int limit;
    cin >> limit;

    ull primes = 0, length = 1, diagonals = 1;
    ull lowerRight, lowerLeft, upperRight, upperLeft;
    do {
        length += 2;
        diagonals += 4;

        lowerRight = length * length;
        lowerLeft = lowerRight - (length - 1);
        upperLeft = lowerLeft - (length - 1);
        upperRight = upperLeft - (length - 1);

        if(millerRabin(lowerLeft))
            primes++;
        if(millerRabin(upperLeft))
            primes++;
        if(millerRabin(upperRight))
            primes++; 

    } while(primes*100 / diagonals >= limit);

    cout << length << endl;

    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler058/