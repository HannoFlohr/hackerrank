#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;
const int MAXSIZE = 1000;

ll powerMod(ll n, int p) {
    if(p==0) return 1;
    if(p==1) return n;
    const ll number = n;
    for(int i=2; i<=p; i++) {
        n *= number;
        n %= MOD;
    }
    return n;
}

int main()
{
    //stores ways a wall with height 1 and width [index] can be built
    // x0=x1=1; x2=2; x3=4; x4=8; x(i) = x(i-1)+x(i-2)+x(i-3)+x(i-4) for i>4
    vector<ll> firstRow (MAXSIZE+1);
    firstRow[0] = firstRow [1] = 1;
    firstRow[2] = 2;
    firstRow[3] = 4;
    firstRow[4] = 8;
    for(int i=5; i<=MAXSIZE; i++) 
        firstRow[i]=(firstRow[i-1]+firstRow[i-2]+firstRow[i-3]+firstRow[i-4]) % MOD;

    //used to store all possibilites to construct a wall with height n and width m
    //allPos(m) = firstRow(i)^n  (includes invalid solutions)
    vector<ll> allPos (MAXSIZE+1);
    
    //used to store valid solutions
    vector<ll> solutions (MAXSIZE+1);
    solutions[0] = solutions[1] = 1;

    int t,n,m;
    long long invalid;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        //compute all possibilities for current m and n
        for(int i=0; i<=m; i++)
            allPos[i] = powerMod(firstRow[i],n);

        //compute possible valid solutions
        for(int i=2; i<=m; i++) {
            invalid = 0;
            //computes the amount of invalid solutions
            for(int j=1; j<i; j++) {
                invalid += (solutions[j] * allPos[i-j]) % MOD;
                invalid %= MOD;
            }
            solutions[i] = allPos[i] - invalid;
            solutions[i] %= MOD;
        }

        //for(auto a:solutions)cerr<<a<<" ";cerr << endl;

        while(solutions[m] < 0)
            solutions[m] += MOD;
        cout<< solutions[m] << endl;
    }
    return 0;
}
