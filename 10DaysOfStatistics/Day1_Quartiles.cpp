#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
    vector<int> a;
    for(int i=0; i<n; i++) {
        cin >> x;
        a.push_back(x);
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
    cout << q1 << endl << q2 << endl << q3 << endl;

    return 0;
}
