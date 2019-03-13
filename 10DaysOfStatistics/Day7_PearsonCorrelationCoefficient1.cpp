#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>
using namespace std;

double mean(const vector<double> &v) {
    double m = 0.0;
    for (int i = 0; i < v.size(); i++)
        m += v[i];
    return m/(double)(v.size());
}

double standardDeviation(const vector<double> &v, const double &mean) {
    double stdDev = 0;
    for (int i = 0; i < v.size(); i++)
        stdDev += (double)pow(v[i] - mean, 2);
    stdDev /= (double)(v.size());
    stdDev = sqrt(stdDev);
    return stdDev;
}

double pearsonCorrelationCoefficient(const vector<double> &vX, const vector<double> &vY) {
    assert(vX.size() == vY.size());
    int n = vX.size();
    double meanX = mean(vX);
    double meanY = mean(vY);

    double sum = 0;
    for(int i=0; i<n; i++) 
        sum += (vX[i]-meanX) * (vY[i]-meanY); 
    
    return sum / (n * standardDeviation(vX,meanX) * standardDeviation(vY,meanY));
}

int main() {
    int n;
    cin >> n;
    vector<double> vX (n);
    vector<double> vY (n);
    for(int i=0; i<n; i++) cin >> vX[i];
    for(int i=0; i<n; i++) cin >> vY[i];

    cout<<fixed<<setprecision(3)<<  pearsonCorrelationCoefficient(vX,vY) <<endl;

    return 0;
}
