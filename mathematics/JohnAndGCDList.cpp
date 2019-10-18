#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t,n,lcm;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v (n);
        for(int i=0; i<n; i++)
            cin >> v[i];

        vector<int> result (n+1);
        result[0] = v[0];
        result[n] = v[n-1];
        for(int i=1; i<n; i++) {
            //compute lowest common multiple 
            lcm = (v[i-1] * v[i]) / (__gcd(v[i-1],v[i]));
            result[i] = lcm;
        }

        for(auto r:result)
            cout << r << " ";
        cout<<endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/john-and-gcd-list/problem