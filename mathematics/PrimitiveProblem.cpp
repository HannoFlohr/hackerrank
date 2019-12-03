#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

//return a^b % mod
ll powMod(ll a, ll b, ll mod) {
    if(b==0)
        return 1;
    ll cur = powMod(a,b>>1,mod) % mod;
    cur = (cur*cur) % mod;
    if(b&1)
        cur = (cur*a) % mod;
    return cur;
} 

int main()
{
    ll p, cur, totalRoots = 0, smallestRoot = -1;
    vector<ll> primeFactors;
    bool check;

    cin >> p;

    //find all unique prime factors of p-1
    cur = p-1;
    for(ll i=2; i*i<=cur; i++) {
        if(cur%i == 0)
            primeFactors.push_back(i);
        while(cur%i == 0)
            cur /= i;
    }
    if(cur > 2)
        primeFactors.push_back(cur);

    //find smallest primitive root
    //http://math.stackexchange.com/questions/124408/finding-a-primitive-root-of-a-prime-number 
    for(ll i=2; i<p; i++) {
        check = true;
        for(auto f : primeFactors) 
            if(powMod(i,p/f,p) == 1) {
                check = false;
                break;
            }
        if(check) {
            smallestRoot = i;
            break;
        }
    }

    //count total primitive roots
    //https://math.stackexchange.com/a/133720
    totalRoots = p-1;
    for(auto f : primeFactors)
        totalRoots = totalRoots / f * (f-1);

    cout << smallestRoot << " " << totalRoots << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/primitive-problem/problem