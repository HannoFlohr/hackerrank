#include <bits/stdc++.h>
using namespace std;

const int MAXBITS = 32;

long andProduct(long a, long b) {
    long x = a, y = b, i = 0;
    while(x>0 && y>0 && x != y) {
        x = x >> 1;
        y = y >> 1;
        i++;
    }
    if(x==y) return x << i;
    else return 0;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        long a, b;
        cin >> a >> b;
        cout << andProduct(a,b) << endl;
    }

    return 0;
}
