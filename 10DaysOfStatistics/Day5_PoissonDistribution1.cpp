#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const double e = exp(1.0);

unsigned long long int faculty(const unsigned long long int &n) {
    if (n == 1 || n == 0) return n;
    else return n * faculty(n - 1);
}

double poissonDistribution(const double &lambda, const unsigned long long int &k) {
    return pow(lambda,k) * pow(e,(-1 * lambda)) / (double)faculty(k);
}

int main() {
    double lambda = 2.5; 
    // k = 5;
    double result = poissonDistribution(lambda,5);
    cout << fixed << setprecision(3) << result << endl;
    return 0;
}
