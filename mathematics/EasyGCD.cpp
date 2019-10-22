#include <bits/stdc++.h>
using namespace std;

//returns the minimal factor of integer 'a'
unsigned int minFactor(unsigned int a) {
    for(unsigned int i=2; i*i<=a; i++)
        if(a%i == 0)
            return i;
    return a;
}

int main()
{
    unsigned int n, k, a, minFac;
    cin >> n >> k;
    unsigned int gcd = 0;
    for(int i=0; i<n; i++) {
        cin >> a;
        gcd = __gcd(gcd,a);
    }

    minFac = minFactor(gcd);

    cout << (k/minFac) * minFac << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/easy-gcd-1/problem