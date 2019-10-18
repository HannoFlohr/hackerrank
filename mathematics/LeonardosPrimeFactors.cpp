#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int MAXN = 150; 
    
    //set up primes using sieve method
    bool prime [MAXN+1];
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=MAXN; p++)
        if(prime[p])
            for(int i=p*p; i<=MAXN; i+=p)
                prime[i] = false;
    vector<int> primes;
    for(int i=2; i<=MAXN; i++)
        if(prime[i])
            primes.push_back(i); 

    int q, count; 
    unsigned long long n, x;
    cin >> q;
    while(q--) {
        cin >> n;

        if(n<2) {
            cout << 0 << endl;
            continue;
        }

        x = 1;
        count = -1;
        do {
            count++;
            x *= primes[count];
        } while(x <= n);

        cout << count << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/leonardo-and-prime/