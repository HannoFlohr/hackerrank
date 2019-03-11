#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, x;
    cin >> a;
    cin >> b;

    cout << a.size() << " " << b.size() << endl;
    x=a+b;
    cout << x << endl;

    char c = a[0];
    a[0] = b[0];
    b[0] = c;

    cout << a << " " << b << endl;
   
    return 0;
}

