#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double n = 100;
    double mu = 500;
    double sigma = 80;
    double z = 1.96;
    double L = mu - z * sigma/sqrt(n);
    double H = mu + z * sigma/sqrt(n);

    cout<<fixed<<setprecision(2)<< L <<endl;
    cout<<fixed<<setprecision(2)<< H <<endl;
    return 0;
}
