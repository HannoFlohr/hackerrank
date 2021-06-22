#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ull n, start, end, cur;
    cin >> n;
        
    //initial range for n-digit numbers    
    end = pow(10,n);
    start = end / 10;

    for(ull i=1; i<=9; i++) {
        cur = i;
        for(ull e=1; e<n && cur < end; e++)
            cur *= i;
        
        if(cur >= start && cur<end)
            cout << cur << endl;
    }
    
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler063/problem