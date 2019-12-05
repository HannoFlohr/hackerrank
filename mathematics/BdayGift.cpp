#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double cur, result;
    cin >> n;
    while(n--) {
        cin >> cur;
        result += 0.5 * cur;
    }
    cout << fixed << setprecision(1) << result << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/bday-gift/problem