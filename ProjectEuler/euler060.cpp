#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned long long int ull;

vector<ull> results;

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

//returns merged a and b
ull merge(ull a, ull b) {
    ull shift = 10;
    while(shift <= b)
        shift *= 10;
    return a * shift + b;
}

//true if a and b can be merged in both ways and are still prime
bool isValidPair(ull a, ull b) {
    return millerRabin(merge(a,b)) && millerRabin(merge(b,a));
}

//checks if 'first' and any two of the candidates form a valid result
void isValidTriplet(const int& first, const vector<int>& candidates) {
    for(size_t i=0; i<candidates.size(); i++)
        for(size_t j=i+1; j<candidates.size(); j++) {
            if(isValidPair(candidates[i], candidates[j])) {
                ull result = first + candidates[i] + candidates[j];
                results.push_back(result);
            }
        }
}

//checks if 'first' and any three of the candidates form a valid result
void isValidQuadruple(const int& first, const vector<int>& candidates) {
    for(size_t i=0; i<candidates.size(); i++)
        for(size_t j=i+1; j<candidates.size(); j++) {
            if(!isValidPair(candidates[i], candidates[j])) 
                continue;
            
            for(size_t k=j+1; k<candidates.size(); k++) {
                if(isValidPair(candidates[i], candidates[k]) && isValidPair(candidates[j], candidates[k])) {
                    ull result = first + candidates[i] + candidates[j] + candidates[k];
                    results.push_back(result);
                }
            }
        }
}

//checks if 'first' and any four of the candidates form a valid result
void isValidQuintuple(const int& first, const vector<int>& candidates) {
    for(size_t i=0; i<candidates.size(); i++)
        for(size_t j=i+1; j<candidates.size(); j++) {
            if(!isValidPair(candidates[i], candidates[j])) 
                continue;
            
            for(size_t k=j+1; k<candidates.size(); k++) {
                if(!isValidPair(candidates[i], candidates[k]) || !isValidPair(candidates[j], candidates[k]))
                    continue;

                for(size_t l=k+1; l<candidates.size(); l++) {
                    if(isValidPair(candidates[i], candidates[l]) && 
                        isValidPair(candidates[j], candidates[l]) &&
                        isValidPair(candidates[k], candidates[l])) {
                            ull result = first + candidates[i] + candidates[j] + candidates[k] + candidates[l];
                            results.push_back(result);
                        }
                }
            }
        }
}

int main() {
    int primeLimit, primeCount;
    cin >> primeLimit >> primeCount;

    //set primes using sieve method
    bool prime[primeLimit+1];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=primeLimit; p++) 
        if(prime[p] == true) 
            for(int i=p*p; i<=primeLimit; i+=p) 
                prime[i] = false;  
    vector<int> primes;
    for(int i=3; i<=primeLimit; i++)
        if(prime[i])
            primes.push_back(i);

    int first, second;
    //loop through all primes to search for valid results
    for(size_t i=0; i<primes.size(); i++) {
        first = primes[i];

        //other than 5 no prime can end with a 5
        if(first == 5) continue;

        //check if another prime forms a pair with the 'first' prime
        vector<int> candidates;
        for(size_t j=i+1; j<primes.size(); j++) {
            second = primes[j];
            if(isValidPair(first,second))
                candidates.push_back(second);
        }

        //check if there are candidates that form a triplet/quadruple/quintuple with 'first'
        if(primeCount == 3)
            isValidTriplet(first, candidates);
        else if(primeCount == 4)
            isValidQuadruple(first, candidates);
        else //primeCount == 5
            isValidQuintuple(first, candidates);
    }

    //sort results and print
    sort(results.begin(),results.end());
    for(auto r : results)
        cout << r << endl;

    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler060/