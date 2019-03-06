#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int N, v;
    cin >> N;
    vector<int> values;
    for(int i=0; i<N; i++) {
        cin >> v;
        values.push_back(v);
    }
    sort(values.begin(),values.end());

    double mean = 0.0;
    for(auto a:values) mean += a;
    mean /= (double)N;

    double stddev = 0;
    for(int i=0; i<N; i++) stddev += (double)pow(values[i]-mean,2);
    stddev /= N;
    stddev = sqrt(stddev);
    cout << fixed << setprecision(1) << stddev << endl;
    return 0;
}
