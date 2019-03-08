#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
    string s = "#";
    for(int i=1; i<=n; i++) {
        cout << setw(n);
        cout << s << endl;
        s += '#';
    }

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
