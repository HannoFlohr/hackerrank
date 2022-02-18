#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;

vector<int> phi_1_n(int n) {
    vector<int> phi (n+1);
    for(int i=0; i<=n; i++)
        phi[i] = i;
    for(int i=2; i<=n; i++) 
        if(phi[i] == i)
            for(int j=i; j<=n; j+=i)
                phi[j] -= phi[j] / i;
                
    return phi;
}

bool isPermutation(int a, int b) {
    string s1=to_string(a);
    string s2=to_string(b);
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    return s1 == s2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    
    vector<int> phi = phi_1_n(N);

    int n=0;
    double min_ratio = numeric_limits<double>::max(), cur_ratio;
    for(int i=10; i<N; i++) {
        cur_ratio = (double)i/phi[i];
        if(cur_ratio < min_ratio) {
            if(isPermutation(i, phi[i])) {
                min_ratio = cur_ratio;
                n = i;
            }
        }
    }
    
    cout << n << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler070/problem