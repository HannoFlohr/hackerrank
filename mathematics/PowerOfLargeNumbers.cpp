#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;
const ll MOD_MINUS1 = 1000000006;

int main()
{
    string a, b;
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll base = 0, power = 0, result = 1;

        // (A+B)%m = (A%m + B%m) %m
        // abcdepqr = (abcde*1000 + pqr)
        for(ll i=0; i<a.size(); i++)
            base = ((base*10) + (a[i]-'0')) % MOD;

        // Fermat's Little Theorm: A^p-1 ≡ 1 % p , where p is a prime number
        for(ll i=0; i<b.size(); i++) 
            power = ((power*10) + (b[i]-'0')) % MOD_MINUS1;

        //compute base^power % MOD
        // (A^B) % MOD = (A * A * ... * A) % MOD = (A % MOD) * ... * (A % MOD)
        while(power) {
            if(power & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            power /= 2;
        }

        cout << result << endl;
    }

    return 0;
}
