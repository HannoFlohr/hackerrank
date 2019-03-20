#include <bits/stdc++.h>

using namespace std;

//count zeros in binary representation of n
//answer will be 2^countZero
//because xor simulates addition without carry
int main()
{
    long long n;
    cin >> n;
    long long count = 0;
    while(n) {
        count += n%2 ? 0 : 1;
        n /= 2;
    }
    count = pow(2, count);
    cout << count << endl;
    return 0;
}
