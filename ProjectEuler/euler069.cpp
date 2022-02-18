#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;
const int MAXP = 100;
vector<int> primes;

void sieveOfEratosthenes() {
    vector<bool> prime(MAXP+1,true);
    for(int p=2; p*p<=MAXP; p++) 
        if(prime[p] == true) 
            for(int i=p*p; i<=MAXP; i+=p) 
                prime[i] = false;

    for(int p=2; p<=MAXP; p++) 
        if(prime[p])
            primes.push_back(p);
}

/*
using brute-force one can see that 
(1)the best n<N is the product of all primes: 
    n = 2*3*5*7*... < N
(2)the product of primes exceedes the maximum N=1e16 for the 16th prime
    -> pre-computing all primes <100 suffices for this problem
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //pre-compute primes
    sieveOfEratosthenes();
    
    int t;
    cin >> t;
    while(t--) {
        ll N;
        cin >> N;
        
        ll posWithBestRatio = 1;
        for(auto p:primes) {
            if(posWithBestRatio * p >= N)
                break;
            posWithBestRatio *= p;
        }

        cout << posWithBestRatio << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler069/problem