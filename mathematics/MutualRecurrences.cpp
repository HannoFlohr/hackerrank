#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MOD = 1000000000ULL;
const int size = 22;

//used to store the last 9 values of x [0]...[8], n*d^n in [9], d^n in [10], 
//the last 9 values of y [11]...[19], n*h^n in [20] and h^n in [21]
vector<ull> values (22,0); 
//the transition matrix
vector<vector<ull>> transitionMatrix (22, vector<ull>(22,0));

//initialize the values vectors for x and y
void init() {
    for(int i=0; i<9; i++) 
        values[i] = 1;
    values[9] = 0;
    values[10] = 1;

    for(int i=11; i<20; i++) 
        values[i] = 1;
    values[20] = 0;
    values[21] = 1;
}

//set the transition matrix
void setTransitionMatrix(ull a, ull b, ull c, ull d, ull e, ull f, ull g, ull h) {
    transitionMatrix = vector<vector<ull>>(22,vector<ull>(22,0));

    transitionMatrix[a-1][0] = 1;
    transitionMatrix[b+10][0]++;
    transitionMatrix[c+10][0]++;
    transitionMatrix[9][0] = 1;

    for(int i=1; i<9; i++) 
        transitionMatrix[i-1][i] = 1;

    transitionMatrix[9][9] = d;
    transitionMatrix[10][9] = d;
    transitionMatrix[10][10] = d;

    transitionMatrix[e+10][11] = 1;
    transitionMatrix[f-1][11]++;
    transitionMatrix[g-1][11]++;
    transitionMatrix[20][11] = 1;

    for(int i=12; i<20; i++) 
        transitionMatrix[i-1][i] = 1;

    transitionMatrix[20][20] = h;
    transitionMatrix[21][20] = h;
    transitionMatrix[21][21] = h;
}

ull addMod(const ull& x, const ull& y) { 
    return ((x+y)%MOD);
}
ull multMod(const ull& x, const ull& y) {
    return ((x*y)%MOD);
}

vector<ull> multMod(const vector<ull>& v, const vector<vector<ull>>& M) {
    vector<ull> result (size,0);
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++) 
            result[i] = addMod(result[i], multMod(v[j], M[j][i]) );
    return result;
}

vector<vector<ull>> multMod(const vector<vector<ull>>& M1, const vector<vector<ull>>& M2) {
    vector<vector<ull>> result (size, vector<ull>(size,0));
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            for(int k=0; k<size; k++) 
                result[i][j] = addMod(result[i][j], multMod(M1[i][k], M2[k][j]) );
    return result;
}

vector<vector<ull>> powMod(vector<vector<ull>> M, ull exponent) {
    //set up as entity matrix
    vector<vector<ull>> result (size, vector<ull>(size,0) );
    for(int i=0; i<size; i++)
        result[i][i] = 1;

    while(exponent > 0) {
        if(exponent & 1)
            result = multMod(result,M);
        
        M = multMod(M,M);
        exponent >>= 1;
    }
    return result;
}

//http://fusharblog.com/solving-linear-recurrence-for-programming-contest/
int main()
{
    ull t,a,b,c,d,e,f,g,h,n;

    cin >> t;
    while(t--) {
        cin>>a>>b>>c>>d>>e>>f>>g>>h>>n;

        init();
        setTransitionMatrix(a, b, c, d, e, f, g, h);
        vector<ull> result = multMod(values, powMod(transitionMatrix,n+1));
        cout << result[0] << " " << result[11] << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/mutual-recurrences/problem