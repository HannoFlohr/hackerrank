#include <bits/stdc++.h>
using namespace std;

int minFactors = 1000000000;
vector<int> factors, current, results;

bool kFactorization(int n, int index) {
    if(index >= factors.size())
        return false;
    if(n == 1)
        return true;
    
    if(n % factors[index] == 0) {
        current.push_back( factors[index] );
        if(kFactorization(n/factors[index], index)) {
            if(current.size() < minFactors) {
                results = current;
                minFactors = results.size();
            }
            return true;
        }
        current.pop_back();
    }
    if(kFactorization(n, index+1)) {
        if(current.size() < minFactors) {
            results = current;
            minFactors = results.size();
        }
        return true;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    factors = vector<int>(k);
    for(int i=0; i<k; i++) cin >> factors[i];
    sort(factors.begin(),factors.end());
    reverse(factors.begin(),factors.end());

    bool validResult = false;
    for(int i=0; i<k; i++) {
        current.clear();
        validResult |= kFactorization(n,i);
    }
    if(validResult) {
        int res = 1;
        cout << "1 ";
        for(int i=results.size()-1; i>=0; i--) {
            res *= results[i];
            cout << res << " ";
        }
        cout << endl;
    }
    else
        cout << "-1" << endl;
    return 0;
}
