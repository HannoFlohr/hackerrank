#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q,x,y;
    cin >> n;
    vector<unsigned long long int> v (n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    cin >> q;
    while(q--) {
        cin >> x >> y;
        x--; y--;

        //find returns v[x]^v[x+1]^...^v[y]
        //if v[x] is odd, all its powers are odd 
        //if v[x] is even, all its powers are even, 
        //unless v[x+1]=0 and x+1<=y -> a^0 = 1 -> odd
        //or x=y and v[x]=0 -> 0^0 = 1
        if((v[x]%2 == 0 && v[x+1] != 0 && x <= y) || 
           (v[x]%2 == 0 && x==y) || 
           (v[x] == 0 && x+1 <= y))
            cout << "Even" << endl;
        else 
            cout << "Odd" << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/even-odd-query/problem