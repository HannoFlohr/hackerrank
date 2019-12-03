#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
/*
    gcd(a,b) = gcd(a+m*b, b)
    -> gcd(a,b) = gcd(a+b,b) = gcd(a,a+b) = gcd(a-b,b) = gcd(a,b-a)
    -> we can move along points with the same gcd
    -> for valid results start and end point need to have the same gcd
*/
int main()
{
    ll t, a, b, x, y, cur;
    
    cin >> t;
    while(t--) {
        cin >> a >> b >> x >> y;

        cout << ( (__gcd(a,b) == __gcd(x,y)) ? "YES" : "NO" ) << endl;
    }
    return 0;
}
//https://www.hackerrank.com/challenges/possible-path/problem