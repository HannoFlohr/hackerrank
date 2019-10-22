#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int t, n, result;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n%2 != 0) {
            cout << 0 << endl;
            continue;
        }

        result = 0; 
        for(unsigned int i=1; i<=sqrt(n); i++) {
            if(n%i == 0) {
                if(i%2 == 0)     
                    result++;
                if(i != n/i && (n/i)%2 == 0)
                    result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/sherlock-and-divisors/problem