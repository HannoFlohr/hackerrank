#include <bits/stdc++.h>
using namespace std;

/*
    for a*b no digits but the first two affect the result

    last two digits of 1^n == 101^n 
    -> a = a + k * 100 (mod 100)

    result = sum up to last a divisible by 100  + remainder
    result = (sum(1,100) * (k/100) % 100) & 100 + (sum(1,k%100)) % 100
*/

typedef long long int ll;
const ll MOD = 100LL;
ll values[101];

//calculates i^n % MOD step by step
ll powMod(ll i, ll n) {
    ll result = 1LL;
    while(n) {
        if(n&1) 
            result = (result * i) % MOD;
        i = (i * i) % MOD;
        n >>= 1;
    }
    return result;
}

ll powerCalculation(const ll &k, const ll &n) {
    ll result = 0LL;
    values[0] = 0LL;

    //calculate last two digits for k^x with x=1...n
    for(ll i=1; i<=100; i++) {
        result = (result + powMod(i, n)) % MOD;
        values[i] = result;
    }

    //result = (sum(1,100) * (k/100) % 100) & 100 + (sum(1,k%100)) % 100
    return ((values[100] * ((k/100) % MOD)) % MOD + values[k%MOD]) % MOD;
}

int main()
{
    ll t, k, n, result;
    cin >> t;
    while(t--) {
        cin >> k >> n;

        result = powerCalculation(k, n);
        if(result < 10) 
            cout << "0";
        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/power-calculation/