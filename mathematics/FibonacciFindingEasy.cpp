#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
ull MOD = 1000000007ULL;
typedef ull Matrix [2][2];
Matrix Q;

void multiply(Matrix M, Matrix N) {
    ull x =  M[0][0]*N[0][0] + M[0][1]*N[1][0]; 
    ull y =  M[0][0]*N[0][1] + M[0][1]*N[1][1]; 
    ull z =  M[1][0]*N[0][0] + M[1][1]*N[1][0]; 
    ull w =  M[1][0]*N[0][1] + M[1][1]*N[1][1];

    Q[0][0] = x % MOD; 
    Q[0][1] = y % MOD; 
    Q[1][0] = z % MOD; 
    Q[1][1] = w % MOD; 
}

//Matrix exponentiation 
void getMatrixPower(ull n) {
    if(n==0 || n==1)
        return;
    
    Matrix N = {{Q[0][0],Q[0][1]},{Q[1][0],Q[1][1]}};

    getMatrixPower(n/2);
    multiply(Q,Q); 

    if(n%2 != 0) 
        multiply(Q,N);
}

//https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
void fibonacciNumber(ull n) {
    if(n==0) 
        return;
    getMatrixPower(n-1);
}

//https://kukuruku.co/post/the-nth-fibonacci-number-in-olog-n/
int main()
{
    int t;
    ull a,b,n;
    cin >> t;
    while(t--) {
        cin >> a >> b >> n;

        if(n==0) 
            cout << a << endl; 
        else if(n==1) 
            cout << b << endl; 
        else {
            Q[0][0] = 0;//a+b;
            Q[0][1] = 1;//b;
            Q[1][0] = 1;//b;
            Q[1][1] = 1;//a;
            
            fibonacciNumber(n);
            ull x = Q[0][0], y = Q[0][1], z = Q[1][0], w = Q[1][1];
            cout << ((y*a % MOD + w * b % MOD) % MOD) << endl;
        }
    }
    return 0;
}
//https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem