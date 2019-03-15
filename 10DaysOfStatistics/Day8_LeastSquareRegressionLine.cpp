#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    vector<int> x = {95,85,80,70,60};
    vector<int> y = {85,95,70,65,70};

    double sumx = 0, sumy = 0, xsquared = 0, xy = 0;
    for(int i=0; i<n; i++) {
        sumx += x[i];
        sumy += y[i];
        xsquared += x[i]*x[i];
        xy += x[i]*y[i];
    }

    double b = ((n * xy) - (sumx * sumy)) / ((n * xsquared) - (sumx * sumx));
    double a = (sumy / n) - b * (sumx / n);

    cout<<fixed<<setprecision(3)<<(a + (b * 80))<<endl;
    return 0;
}
