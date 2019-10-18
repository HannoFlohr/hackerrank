#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> divisors;
    for(int i=1; i<=n; i++)
        if(n%i==0)
            divisors.push_back(i);

    int cur, digitSum, maxDigitSum = 0, bestDivisor = 0;
    for(int i=0; i<divisors.size(); i++) {
        cur = divisors[i];
        digitSum = 0;
        while(cur>0) {
            digitSum += (cur % 10);
            cur /= 10;
        }

        if( (digitSum > maxDigitSum) || 
            (digitSum == maxDigitSum && divisors[i] < bestDivisor) ) {
            maxDigitSum = digitSum;
            bestDivisor = divisors[i];
        }
    }
    
    cout << bestDivisor << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/best-divisor/problem