#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, type;
    int result_type = 0, result_k = 0;
    bool sign = false;
    cin >> n >> m;

    while(m--) {
        cin >> type >> k;

        result_type ^= type - 1;
        result_k += (2 * result_type - 1) * k + n;
        result_k %= n;
    }

    cout << (result_type+1) << " " << result_k << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/xrange-and-pizza/problem