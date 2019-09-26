#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

typedef unsigned long long int ull;
const int MAXN = 1000001;

//returns the count of each digit in 'number' 
ull digitCount(ull number) {
    ull digit, pos, result = 0;
    while(number > 0) {
        digit = number % 10;
        number /= 10;
    
        pos = 1;
        for(int i=1; i<=digit; i++)
            pos *= 10;
        result += pos;
    }
    return result;
}

int main() {
    //set set of primes using sieve method
    bool prime[MAXN];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=MAXN; p++) 
        if(prime[p] == true) 
            for(int i=p*p; i<=MAXN; i+=p) 
                prime[i] = false; 
    set<ull> primes;
    for(int i=2; i<MAXN; i++) 
        if(prime[i])
            primes.insert(i);

    //count the digits of all primes and map them
    map<ull,ull> digitCountPrimes;
    for(auto p:primes)
        digitCountPrimes[digitCount(p)]++;
    
    //read input
    int n, k;
    cin >> n >> k;
    
    map<ull,set<string>> result;
    string s;
    ull x;

    for(auto p:primes) {
        //skip primes not in required range
        if(p<1000) 
            continue;
        if(p>=n) 
            break;

        //check if enough primes share the digit count of this prime
        if(digitCountPrimes[digitCount(p)] < 3)
            continue;

        s = to_string(p);
        sort(s.begin(),s.end());

        //find prime permutations
        set<ull> candidates;
        do {
            //no leading zero
            if(s[0] == '0') continue;

            x = stoi(s);
            //check if permutation is prime
            if(primes.count(x) == 0)
                continue;

            //skip if this prime was encountered before
            if(x < p)
                break;

            candidates.insert(x);
        } while(next_permutation(s.begin(), s.end()));

        //skip if too few candidates
        if(candidates.size() < k)
            continue;

        //compute the differences between the primes
        map<ull,set<ull>> differences;
        for(auto a : candidates)
            for(auto b : candidates) {
                if(b >= a)
                    break;
                differences[a-b].insert(a);
                differences[a-b].insert(b);
            }

        //check all differences for valid results
        ull difference, count, next;
        set<ull> numbers;
        for(auto d : differences) {
            if(d.second.size() < k)
                continue;

            difference = d.first;
            numbers = d.second;

            //check if its a sequence
            for(auto cur : numbers) {
                if(cur >= n) continue;

                count = 0;
                next = cur + difference;
                while(numbers.count(next) != 0) {
                    count++;
                    next += difference;
                }

                if(count >= k-1) {
                    next = cur + difference;
                    string res = to_string(cur);
                    for(int i=1; i<k; i++) {
                        res += to_string(next);
                        next += difference;
                    }
                    result[res.size()].insert(res);
                }
            }
        }

    }

    for(auto r : result)
        for(auto x : r.second)
            cout << x << endl;

    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler049/