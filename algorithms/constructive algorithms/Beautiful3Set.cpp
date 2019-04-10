#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
each |X|, |Y|, |Z| has k+1 elements; 0...k belong to each of X,Y,Z
all k elements are distinct
k can be determined by solving quadratic equation
3 * k * (k+1) / 2 = (k+1) * n
-> k = 2*n/3

example: n=3: elements: 0 1 2 -> k=2 -> k+1=3 distinct elements in each

x+y+z=n
let z=0, y=k, x=? -> ?=n-k 
let z=0, y=p, x=? -> p=k-?=k-n+k=   2k-n = y
x = n-y-z = n-2k-n = 2n-2k

for y=0..p-1 it can be shown that
x=0 pairs with y=3n-4k+1
till
x=2k-n-1 pairs with y=2n-2k
*/
int main() {
    int n, k, x, y;
    cin >> n;
    k = (2 * n) / 3;
    cout << k+1 << endl;

    y = 2 * k - n;
    x = n - 2 * y;
    for(int i=0; i<=y; i++)
        cout << i << " " << x+i << " " << n-x-2*i << endl;
    for(int i=0; i<k-y; i++)
        cout << y+i+1 << " " << i << " " << n-y-1-2*i << endl;
      
    return 0;
}
