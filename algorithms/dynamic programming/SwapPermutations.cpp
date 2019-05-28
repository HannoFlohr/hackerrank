#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;
const int MAXVALUE = 2500; // n,k <= 2500
ll A[MAXVALUE+1][MAXVALUE+1]; // # of permutations of length i with j inversions
ll B[MAXVALUE+1][MAXVALUE+1]; // # of graphs with j cycles
ll C[MAXVALUE+2];
int n, k;

void add(int pos, ll value) {
    while(pos <= MAXVALUE+1) {
        C[pos] = (C[pos] + value) % MOD;
        pos += (pos)&(-pos);  //power of least significant ‘1’ bit in a binary number
    }
}

void update(int left, int right, ll value) {
    add(++left, value);
    add(right+2, -value);
}

ll getValue(int x) {
    x++;
    ll result = 0;
    while(x > 0) {
        result = (result + C[x]) % MOD;
        x -= (x)&(-x);
    }
    return result;
}

int main()
{
    cin >> n >> k;

    A[1][0] = 1;
    for(int i=1; i<MAXVALUE; i++) {
/*
    if we are at state i,j and want to add element i+1, we have i+1 positions to choose
    from, and each position will create one inversion more than the position to its 
    right. if we push it to the back of the array, we dont create any new inversions. 
    if we push it to the front of the array, we create i new inversions
    -> add A[i][j] to all A[i][k] for k=j..j+i
*/
        for(int j=0; j<=MAXVALUE; j++)
            update(j, min(j+i,MAXVALUE), A[i][j]);
        for(int j=0; j<=MAXVALUE; j++) 
            A[i+1][j] = getValue(j);
        for(int j=0; j<=MAXVALUE+1; j++)
            C[j] = 0;
    }

    B[1][1] = 1;
    for(int i=0; i<MAXVALUE; i++) {
        for(int j=1; j<=i; j++) {
/*
    if we are at state i,j and want to add element i+1:
    1) point to itself, creating new cycle
    2) point to previous element, extending one existing cycles length by 1
    i positions for second choice
    -> add B[i][j] to B[i+1][j+1] and
           B[i][j]*i to B[i+1][j]
*/
            B[i+1][j+1] = (B[i+1][j+1] + B[i][j]) % MOD;
            B[i+1][j] = (B[i+1][j] + B[i][j] * i) % MOD;
        }
    }

    ll result = 0, result2 = 0;
    for(int j=k; j>=0; j-=2) 
        result += A[n][j];
    for(int i=0; i <= min(k,n-1); i++)
        result2 += B[n][n-i];

    cout << result % MOD << " " << result2 % MOD << endl;

    return 0;
}
