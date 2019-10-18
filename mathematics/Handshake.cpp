#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, handshakes;
    cin >> t;
    while(t--) {
        cin >> n;
        handshakes = (n * (n-1)) / 2;
		cout << handshakes << endl;
    }

    return 0;
}
//https://www.hackerrank.com/challenges/handshake/problem