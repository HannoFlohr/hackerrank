#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

//returns the geometric distribution g(n,p)
double geometricDistribution(const unsigned long long int &n, double &p) {
    return pow(1-p,n-1) * p;
}

int main() {
    double p = 1.0 / 3.0;
    cout << fixed << setprecision(3) << geometricDistribution(5,p) << endl;
    return 0;
}
