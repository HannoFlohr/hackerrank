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
    double mu = 70;
    double sigma = 10;

    double res;
    res = cumulativeNormalDistribution(mu,sigma,80);
    cout<<fixed<<setprecision(2)<< (1-res)*100 <<endl;

    res = cumulativeNormalDistribution(mu,sigma,60);
    cout<<fixed<<setprecision(2)<<(1-res)*100<<endl;

    //res = cumulativeNormalDistribution(mu,sigma,60);
    cout<<fixed<<setprecision(2)<<(res*100)<<endl;

    return 0;
}
