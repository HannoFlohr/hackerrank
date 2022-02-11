#include<bits/stdc++.h>
using namespace std;

const long long int MAXN = (long long int)sqrt(1e15);
vector<long long int> primes;

void sieveOfEratosthenes() {
    bool prime[MAXN+1];
    memset(prime, true, sizeof(prime));
    
    for(long long p=2; p*p<=MAXN; p++) 
        if(prime[p] == true) 
            for(long long i=p*p; i<=MAXN; i+=p) 
                prime[i] = false;

    for(long long p=2; p<=MAXN; p++) 
        if(prime[p])
            primes.push_back(p);
}

//one-digit primes: 2,3,5,7
bool isMegaprime(long long int n) { 
    int digit;
    while(n) {
        digit = int(n%10);
        if(digit!=2 && digit!=3 && digit!=5 && digit!=7) 
            return false;
        n /= 10;
    }
    return true;
}

void countMegaprimesInRange(const long long& first, const long long& last, long long &count) {
    if(first>last) return;
    
    vector<bool> isPrime(last-first+1,true);
    for(auto p:primes) {
        if(p*p > last) 
            break;
        for(long long j=max(p, (first+p-1)/p)*p; j<=last; j+=p) 
            isPrime[j-first] = false;
    }
    
    for(long long i=first; i<=last; i++) 
        if(isPrime[i-first] && isMegaprime(i))
            count++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long int first, last, start, stop, count=0;
    cin >> first >> last;
    
    sieveOfEratosthenes();
    
    /* 
    digits can only be 2,3,5,7
    therefore in a 7 digit-range possible megaprimes can only be in 
    range [2222222,7777777]
    */
    const int chunk       = 10000000;
    const int chunk_min   = 2222222;
    const int chunk_max   = 7777777;
    const int chunk_first = 777777;
    
    if(last <= chunk_first) 
        countMegaprimesInRange(first, last, count);
    else {
        if(first <= chunk_first) {
            countMegaprimesInRange(first, chunk_first, count);
            first = chunk_first+1;
        }
        for(start=(first/chunk)*chunk+chunk_min; start<=last; start+=chunk) {
            if(isMegaprime(start)) {
                stop = start - chunk_min + chunk_max; 
                countMegaprimesInRange(max(first,start), min(last,stop), count);
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/megaprime-numbers/problem