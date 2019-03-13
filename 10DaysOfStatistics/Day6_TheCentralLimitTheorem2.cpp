#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double cumulativeNormalDistribution(const double &mu, const double &sigma, const double &x) {
    return 0.5 * (1.0 + erf( (x-mu) / (sigma * sqrt(2)) )  );
}

int main() {
    double x = 250;
    double n = 100;
    double mu = 2.4 * n;
    double sigma = 2.0 * sqrt(n);
    cout<<fixed<<setprecision(4)<< cumulativeNormalDistribution(mu,sigma,x) <<endl;
    return 0;
}
