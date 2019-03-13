#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double normalDistribution(const double &mu, const double &sigma, const double &x) {
    double result = 1.0 / (sigma * sqrt(2.0 * M_PI));
    double exp = -1.0 * pow(x-mu,2) / (2.0 * sigma *sigma);
    return pow(result,exp); 
}

double cumulativeNormalDistribution(const double &mu, const double &sigma, const double &x) {
    return 0.5 * (1.0 + erf( (x-mu) / (sigma * sqrt(2)) )  );
}

int main() {
    double x = 9800;
    double n = 49;
    double mu = 205 * n;
    double sigma = 15 * sqrt(n);
    cout<<fixed<<setprecision(4)<< cumulativeNormalDistribution(mu,sigma,x) <<endl;
    return 0;
}
