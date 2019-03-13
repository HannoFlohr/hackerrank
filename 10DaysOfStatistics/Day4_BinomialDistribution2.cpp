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
    double prob = 0.12;
    double result = 0.0;
    for(int k=0; k<=2; k++)
        result += binomialDistribution(10,k,prob);
    cout << fixed << setprecision(3) << result << endl;

    result = 0.0;
    for(int k=2; k<=10; k++)
        result += binomialDistribution(10,k,prob);
    cout << fixed << setprecision(3) << result << endl;
    return 0;
}
