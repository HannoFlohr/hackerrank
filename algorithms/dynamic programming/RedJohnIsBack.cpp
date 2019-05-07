#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40;
int dp[MAXN+1][MAXN+1];

int countPossibilities(int n) {
    int possibilities = 0, remainingBricks;
    const int maxSquares = n / 4;
    for(int squares = 0; squares <= maxSquares; squares++) {
        remainingBricks = n - squares * 4;
        possibilities += dp[remainingBricks+squares][squares];
    }
    return possibilities;
}

int main()
{
    // dp(i,0) = 1
    for(int i=0; i<=MAXN; i++)
        dp[i][0] = 1;
    // dp(i,j) = dp(i-1,j) + dp(i-1,j-1)
    for(int i=1; i<=MAXN; i++) {
        for(int j=1; j<=MAXN; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    //compute primes list using sieve of eratosthenes
    //possibilities for n=40: 217286
    bool prime [217287];
    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=217286; p++) {
        if(prime[p] == true) {
            for(int i=p*p; i<=217286; i+=p) {
                prime[i] = false;
            }
        }
    }
    vector<int> primes;
    for(int p=2; p<=217286; p++) 
        if(prime[p])
            primes.push_back(p);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;

        int possibilities = countPossibilities(n);

        int result = 0;
        for(auto p:primes) {
            if(p > possibilities)
                break;
            result++;
        }
        cout << result << endl;
    }

    return 0;
}
