#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, x;
    unsigned long long digitSum;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a (n);
        for(int i=0; i<n; i++)
            cin >> a[i];

        //Numbers are divisible by 3 if the sum of all the individual digits is evenly divisible by 3
        digitSum = 0LL;
        for(int i=0; i<n; i++) {
            x = a[i]; 
            while(x > 0) {
                digitSum += x%10;
                x /= 10;
            }
        }
        cout << ((digitSum%3 == 0) ? "Yes" : "No") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/constructing-a-number/problem