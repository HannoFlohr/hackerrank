#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    ull a, b, result=2;
    cin >> a >> b;
    
    for(int i=0; i<a; i++)
        result = (result*result) % b;
        
    cout << result << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/superpowers/problem