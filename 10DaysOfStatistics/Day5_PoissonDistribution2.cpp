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
    double lambdaA = 0.88, lambdaB = 1.55; 
    cout<<fixed<<setprecision(3)<<(160.0 + 40.0 * (lambdaA + pow(lambdaA,2)) )<<endl;
    cout<<fixed<<setprecision(3)<<(128.0 + 40.0 * (lambdaB + pow(lambdaB,2)) )<<endl;
    return 0;
}
