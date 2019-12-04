#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
const ull MOD = 1000007;

bool isPrime(ull p) {
    if(p==2 || p==3) 
        return true;

    bool prime = true;
    for(ull i=2; i<=sqrt(p); i++) 
        if(p%i == 0) {
            prime = false;
            break;
        }
    return prime;
}

/*
    (1/x) + (1/y) = (1/N!)      N! == p
    (x+y)/(xy) = (1/p)
    xy - px - py = 0            / +p^2
    p^2 - px - py = p^2
    p(p-x) - y(p-x) = p^2
    (p-x)(p-y) = p^2
    A * B = p^2
    A * B = N!^2
    -> find amount of divisors of N!^2 for solution 
*/
int main()
{
    ull n, result=1, power, count;
    cin >> n;

    for(ull i=2; i<=n; i++) {
        if(isPrime(i)) {
            power = 1;
            count = 0;
            while(pow(i,power) <= n) {
                count += (n/pow(i,power));
                power++;
            }
            result *= (2*count + 1);
            result %= MOD;
        }
    }
    
    cout << result << endl;

    return 0;
}
//https://www.hackerrank.com/challenges/equations/problem