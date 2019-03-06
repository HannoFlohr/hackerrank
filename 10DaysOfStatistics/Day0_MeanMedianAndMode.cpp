#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
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

    double mean = 0;
    for(auto a:values) mean += a;
    mean /= (double)N;
    cout << mean << endl;

    double median = 0; 
    if(values.size()%2 != 0) median = values[values.size()/2];
    else median = (values[values.size()/2] + values[ (values.size()/2) - 1]) / 2.0;
    cout << median << endl;

    map<int,int> freq;
    for(auto a:values) freq[a]++;
    int mode = -1, maxFreq=0;
    for(auto a:freq) {
        if(a.second > maxFreq) {
            maxFreq = a.second;
            mode = a.first;
        }
    }
    cout << mode << endl;

    return 0;
}
