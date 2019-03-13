#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

unsigned int binomialCoefficient(const unsigned int& n, const unsigned int& k) {
    if(k==0) return 1;
    else if(k > n) return 0;
    else 
        return binomialCoefficient(n-1,k-1) +
                binomialCoefficient(n-1,k);
}

double binomialDistribution(const unsigned int &n,const unsigned int &k,const double &p){
    return (double)(binomialCoefficient(n,k)) * pow(p,k) * pow(1-p,n-k);
}

int main() {
    double probBoys = 1.09 / (1.09 + 1.0);
    double result = 0.0;
    for(int k=3; k<=6; k++)
        result += binomialDistribution(6,k,probBoys);

    cout << fixed << setprecision(3) << result;
    return 0;
}
