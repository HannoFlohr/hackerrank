#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int n,x;
    cin>>n;
    vector<int> v, w;
    for(int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }   
    for(int i=0; i<n; i++) {
        cin >> x;
        w.push_back(x);
    }   

    double sumWeights = 0, sumWeightedValues=0;
    for(int i=0; i<n; i++) {
        sumWeightedValues += v[i] * w[i];
        sumWeights += w[i];
    }

    double result = sumWeightedValues/sumWeights;
    cout << fixed << setprecision(1) << result << endl;

    return 0;
}
