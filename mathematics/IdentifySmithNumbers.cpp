#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
vector<int> primes;

int primeFactorSum(int n) {
    vector<int> factors;
    for(int i=0; i<primes.size(); i++) {
        while(n%primes[i] == 0) {
            factors.push_back(primes[i]);
            n /= primes[i];
        }
    }

    int sum = 0;
    for(int i=0; i<factors.size(); i++) {
        while(factors[i]>0) {
            sum += factors[i]%10;
            factors[i] /= 10;
        }
    }
    return sum;
}

int main()
{
    int n, digitSum, pFsum;
    cin >> n;

    memset(prime, true, sizeof(prime));
    for(int p=2; p*p<=1000000; p++) 
        if(prime[p])
            for(int i=p*p; i<=1000000; i+=p)
                prime[i] = false;
    for(int i=2; i<=1000000; i++)
        if(prime[i])
            primes.push_back(i);

    pFsum = primeFactorSum(n);

    while(n>0) {
        digitSum += n%10;
        n /= 10;
    }

    cout << (digitSum == pFsum ? 1 : 0) << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/identify-smith-numbers/problem