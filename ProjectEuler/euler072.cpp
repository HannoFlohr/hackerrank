#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
vector<int> phi (MAXN+1);

void phi_1_n(int n=MAXN) {
    for(int i=0; i<=n; i++)
        phi[i] = i;
    for(int i=2; i<=n; i++) 
        if(phi[i] == i)
            for(int j=i; j<=n; j+=i)
                phi[j] -= phi[j] / i;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //precompute all phi(x) up to MAXN=1e6
    phi_1_n();
    
    //compute sums of all phi values for primes: 
    //sums[i] contains the the sum of all phi(x) up to x
    vector<unsigned long long int> sums (phi.size(), 0);
    for(unsigned int i=2; i<=MAXN; i++) 
        sums[i] = sums[i-1] + phi[i];
    
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << sums[n] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler072/problem