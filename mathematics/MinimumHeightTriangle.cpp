#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int b, a;
    cin >> b >> a;
    cout << ( 2 * a / b +  bool((2 * a) % b) )  << endl;
    return 0;
}
//https://www.hackerrank.com/challenges/lowest-triangle/problem