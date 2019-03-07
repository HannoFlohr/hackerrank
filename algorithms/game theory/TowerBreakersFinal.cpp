#include <bits/stdc++.h>

using namespace std;

const int LIMIT = 130;   //2^130 > 1e18

vector<long long> D;

//a(n) = 1, if n = 0;  a(n)=Sum(1 <= k^2 <= n, a(n-k^2)), if n > 0.
//def a(n): return 1 if n==0 
//else sum([a(n - k) for k in xrange(1, n + 1) if is_square(k)])
long long initD(long long n) { 
    if(D[n] != 0) 
        return D[n];
    else{
        long long x = 0LL;
        for(int k=1; k<(int)(sqrt(n))+1; k++)
            x += initD( n - (k*k) );
        D[n] = x;
        return D[n];
    }
}

long long towerBreakers(long long n) {
    int res=0;
    while( D[res]<n ) res++;
    return res;
}

int main()
{
    //initialize
    D = vector<long long>(LIMIT);
    D[0]=1;
    initD(LIMIT);

    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long long result = towerBreakers(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
