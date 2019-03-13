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
    double mu = 20;
    double sigma = 2;

    cout<<fixed<<setprecision(3)<<cumulativeNormalDistribution(mu,sigma,19.5)<<endl;

    double res1, res2;
    res1 = cumulativeNormalDistribution(mu,sigma,20);
    res2 = cumulativeNormalDistribution(mu,sigma,22);
    cout<<fixed<<setprecision(3)<<res2-res1<<endl;

    return 0;
}
