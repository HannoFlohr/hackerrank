#include <bits/stdc++.h>

using namespace std;

void extraLongFactorials(int n) {
    if(n==1) {
        cout << "1" << endl;
        return;
    }
    vector<int> res (1,1);
    vector<int>::iterator it;
    for(int i=2; i<=n; i++) {
        for(it = res.begin(); it!=res.end(); it++)
            *it *= i;
        for(int j=0; j<res.size(); j++) {
            if(res[j] >= 10) {
                if(j == res.size()-1)
                    res.push_back(0);
                    res[j+1] += res[j]/10;
                    res[j] %= 10;
            } 
        }
    }
    for(int i=res.size()-1; i>=0; i--)
        cout << res[i];
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
