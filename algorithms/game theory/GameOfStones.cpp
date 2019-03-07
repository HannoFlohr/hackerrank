#include <bits/stdc++.h>
using namespace std;


string gameOfStones(int n) {
    return (n%7 < 2) ? "Second" : "First";
}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string result = gameOfStones(n);
        cout << result << endl;
    }
    return 0;
}
