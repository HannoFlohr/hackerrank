#include <bits/stdc++.h>
using namespace std;

/*
    find smallest values for a and be
    result = min_a * min_b
*/
int main()
{
    unsigned long long int n,a,b,min_a=numeric_limits<int>::max(),min_b=numeric_limits<int>::max();
    cin >> n;
    while(n--) {
        cin >> a >> b;
        if(a < min_a) min_a = a;
        if(b < min_b) min_b = b;
    }
    cout << (min_a * min_b) << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/rectangular-game/problem