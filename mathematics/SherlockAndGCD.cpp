#include <bits/stdc++.h>
using namespace std;

//recursively returns the gcd of array 'a'
int arrayGcd(vector<int> a) {
    if(a.size() == 2)
        return __gcd(a[0],a[1]);

    int last = a.back();
    a.pop_back();
    return __gcd(last, arrayGcd(a));
}

int main()
{
    int t, n;
    cin >> t;
    while(t--) { 
        cin >> n;
        vector<int> a (n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        if(n<2) {
            cout << "NO" << endl;
            continue;
        }

        cout << (arrayGcd(a)==1 ? "YES" : "NO") << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/sherlock-and-gcd/problem