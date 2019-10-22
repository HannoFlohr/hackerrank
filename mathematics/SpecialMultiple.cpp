#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;

int main()
{
    //precompute array with all permutations 9 90 99 900 909 990 999 9000....
    ull numbers[10001] = {0};
    ull x, j;
    for(ull i=1; i<10000; i++) {
        j = i;
        x = 1ULL;
        while(j) {
            numbers[i] += (j%2) * x * 9ULL;
            j /= 2ULL;
            x *= 10ULL;
        }
    }
    //for(int i=1; i<=20; i++)cout<<numbers[i]<<" ";cout<<endl;

    int t;
    cin >> t;
    while(t--) {
        ull n;
        cin >> n;
        for(int i=1; i<10000; i++)
            if(numbers[i]%n == 0) {
                cout << numbers[i] << endl;
                break;
            }
    }
    return 0;
}
//https://www.hackerrank.com/challenges/special-multiple/problem