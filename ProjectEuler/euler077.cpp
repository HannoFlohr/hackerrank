#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
vector<int> primes;
int n;

void sieveOfEratosthenes() {
    vector<bool> prime (MAXN+1, true);
    for(int p=2; p*p<=MAXN; p++) 
        if(prime[p] == true) 
            for(int i=p*p; i<=MAXN; i+=p) 
                prime[i] = false;

    for(int p=2; p<=MAXN; p++) 
        if(prime[p])
            primes.push_back(p);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    sieveOfEratosthenes();
    
    vector<unsigned long long> w (MAXN+1);
    w[0]=1;
    for(auto &p: primes) 
        for(int i=p; i<=MAXN; i++)
            w[i] += w[i-p];
        
    int t, ways;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << w[n] << endl;
    }
    return 0;
}

#https://www.hackerrank.com/contests/projecteuler/challenges/euler077/problem