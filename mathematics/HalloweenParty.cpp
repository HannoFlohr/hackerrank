#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long int t,k;
    cin >> t;
    while(t--) {
        cin >> k;
        if(k%2 == 0)
            cout <<  (k/2)*(k/2) << endl;
        else 
            cout << (k/2) * ((k/2)+1) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/halloween-party/problem