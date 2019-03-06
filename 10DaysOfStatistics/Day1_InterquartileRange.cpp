#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double median(const vector<int>& a) {
    double median = 0; 
    if(a.size()%2 != 0) median = a[a.size() / 2];
    else median = (a[a.size() / 2] + a[a.size() / 2 - 1]) / 2.0;
    return median;
}

int main() {
    int n,x;
    cin >> n;
    vector<int> values;
    vector<int> freq;
    for(int i=0; i<n; i++) {
        cin >> x;
        values.push_back(x);
    }
    for(int i=0; i<n; i++) {
        cin >> x;
        freq.push_back(x);
    }

    vector<int> a;
    for(int i=0; i<n; i++) {
        x = freq[i];
        while(x--)
            a.push_back(values[i]);
    }
    sort(a.begin(),a.end());
    
    vector<int> lower (0);
    vector<int> upper (0);
    int mid = a.size() / 2;
    if(a.size()%2 == 0) {
    lower.insert(lower.end(),a.begin(),a.begin()+mid);
    upper.insert(upper.end(),a.begin()+mid,a.end() );
    }
    else {
    lower.insert(lower.end(),a.begin(),a.begin()+mid);
    upper.insert(upper.end(),a.begin()+mid+1,a.end() );
    }

    double q1, q2, q3;
    q1 = median(lower);
    q2 = median(a);
    q3 = median(upper);
    cout << fixed << setprecision(1) << q3-q1 << endl;

    return 0;
}
