#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int addMod(int a, int b) {
    return (a+b) % MOD;
}
int subMod(int a, int b) {
    return (a-b+MOD) % MOD;
}

int mulMod(int a, int b) {
    return (int)((long)a * b % MOD);
}
//returns (base^exp) % mod
int powMod(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        //odd exponent a^b = a*a^(b-1)
        if (exp & 1)
            result = mulMod(result, base);
        //even exponent a^b = (a*a)^(b/2)
        base = mulMod(base, base);
        exp >>= 1;
    }
    return result;
}

//returns modular inverse for x;
int inverseMod(int x) {
    return powMod(x, MOD-2);
}

int tangentSum(int a, int b) {
    return mulMod(addMod(a,b), inverseMod(subMod(1,mulMod(a,b))));
}

int main()
{
    int t, p, q, n, base, result;
    cin >> t;
    while(t--) {
        cin >> p >> q >> n;

        base = mulMod(p, inverseMod(q));
        result = 0;

        for(int i=n; i!=0; i/=2) {
            if(i%2 != 0)
                result = tangentSum(result,base);

            base = tangentSum(base, base);
        }

        cout << result << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/simple-one/problem