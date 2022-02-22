#include<bits/stdc++.h>
using namespace std;

const unsigned MAXN = 10000000;

vector<unsigned> primes;
void sieveOfEratosthenes() {
    vector<bool> prime(MAXN+1,true);
    for(unsigned p=2; p*p<=MAXN; p++) 
        if(prime[p] == true) 
            for(unsigned i=p*p; i<=MAXN; i+=p) 
                prime[i] = false;

    for(unsigned p=2; p<=sqrt(MAXN); p++) 
        if(prime[p])
            primes.push_back(p);
}

//446 squares
//47 cubes
//16 fourths  
//335392 combinations; 266772 combinations <= MAXN
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //precompute all primes up to MAXN
    sieveOfEratosthenes();
    
    //precompute all possible prime^2 + prime^3 + prime^4
    vector<unsigned> possible_results;
    for(auto s:primes) {
        for(auto c:primes) 
            for(auto f:primes) {
                auto square = s * s;
                auto cube = (unsigned long long)c * c * c;
                auto fourth = (unsigned long long)f * f * f *f;
                auto x = square + cube + fourth;
                if(x>MAXN) 
                    break; 
                
                possible_results.push_back(x);
            }
    }
    //sort and make unique
    sort(possible_results.begin(), possible_results.end());
    auto last_item = unique(possible_results.begin(), possible_results.end());

    unsigned t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        
        auto it = upper_bound(possible_results.begin(), last_item, n);
        cout << (it - possible_results.begin()) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler087/problem