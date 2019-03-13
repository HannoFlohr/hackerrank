#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

vector<int> setRanks(const vector<double> &v) {
    vector<double> sorted = v;
    sort(sorted.begin(),sorted.end());

    map<double,int> m;
    for(int i=0; i<v.size(); i++) 
        m[sorted[i]] = i+1;
    
    vector<int> ranks (v.size());
    for(int i=0; i<v.size(); i++) 
        ranks[i] = m[v[i]];
    return ranks;
}
double spearmanRankCorrelationCoefficient(const vector<double> &x, const vector<double> &y) {
    assert(x.size() == y.size());
    int n = x.size();
    vector<int> ranksX = setRanks(x);
    vector<int> ranksY = setRanks(y);

    vector<int> d (n);
    for(int i=0; i<n; i++) {
        d[i] = ranksX[i] - ranksY[i];
        d[i] *= d[i];
    }

    double result = 0;
    for(int i=0; i<n; i++) 
        result += d[i];
    result = 6.0 * result / (n * ((n*n)-1) );
    return 1.0 - result;
}

int main() {
    int n;
    cin >> n;
    vector<double> vX (n);
    vector<double> vY (n);
    for(int i=0; i<n; i++) cin >> vX[i];
    for(int i=0; i<n; i++) cin >> vY[i];

    cout<<fixed<<setprecision(3)<<  spearmanRankCorrelationCoefficient(vX,vY) <<endl;

    return 0;
}
