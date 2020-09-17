#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
vector<int> perfectSquares;

void setup() {
    int cur = 1, square = 1;
    while(square < MAXN) {
        if(square%2 == 0)
            perfectSquares.push_back(square); 
        cur++;
        square = cur * cur;
    }
}

int primeFactors(int n) {
    map<int, int> pf;
    int count = 0, factors = 1;
    
    while(n%2 == 0) {
        n /= 2;
        count++;
    }
    if(count>0) pf.insert(pair<int,int>(2,count));

    for(int i=3; i<=(sqrt(n)+1); i+=2) {
        count = 0;
        while(n%i==0) {
            n /= i;
            count++;
        }
        if(count>0) pf.insert(pair<int,int>(i,count));
    }

    if(n>2) pf.insert(pair<int,int>(n,1));

    for(map<int,int>::iterator it = pf.begin(); it!=pf.end(); ++it)
        factors *= (it->second + 1);
    
    return factors-1;
}

int main()
{
    setup();

    int t, n, divisors, perfectSquareDivisors, cur, div;
    cin >> t;
    while(t--) {
        cin >> n;

        divisors = primeFactors(n);
        perfectSquareDivisors = 0;
        cur = 0;

        if(n%2==0) { 
            while(perfectSquares[cur] <= n/2) {
                if(n%perfectSquares[cur] == 0)
                    perfectSquareDivisors++;
                cur++;
            }

            if(perfectSquareDivisors != 0) {
                div = __gcd(perfectSquareDivisors,divisors);
                if(div != 1)
                    cout << (perfectSquareDivisors/div) << "/" << (divisors/div) << endl;
                else 
                    cout << perfectSquareDivisors << "/" << divisors << endl;
            }
            else 
                cout << 0 << endl;
        }
        else
            cout << 0 << endl;
        

    }
    return 0;
}
//https://www.hackerrank.com/challenges/mehta-and-his-laziness/problem