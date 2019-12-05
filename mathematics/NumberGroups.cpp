#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int k, cur = -1, sum = 0;
    cin >> k;

    for(int i=1; i<k; i++)
        cur += 2*i;

    for(int i=1; i<=k; i++) {
        cur += 2;
        sum += cur;
    }

    cout << sum << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/number-groups/problem