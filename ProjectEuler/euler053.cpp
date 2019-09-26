#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long int ull;
const ull MAXN = 1000;

int main() {
    ull N, K, sum, result=0ULL;
    cin >> N >> K;

    vector<vector<ull>> C(MAXN+1, vector<ull>(MAXN+1,0LL));

    //nC0 = nCn = 1;
    for(unsigned int n=0; n<=MAXN; n++) 
        C[n][0] = C[n][n] = 1LL;

    //nCk = n-1Ck-1 + n-1Ck
    for(unsigned int n=1; n<=N; n++)
        for(unsigned int k=1; k<=N; k++) {
            sum = C[n-1][k-1] + C[n-1][k];

            if(sum > K) {
                sum = K+1;
                result++;
            }

            C[n][k] = sum;
        }

    cout << result << endl;
    return 0;
}

//https://www.hackerrank.com/contests/projecteuler/challenges/euler053/