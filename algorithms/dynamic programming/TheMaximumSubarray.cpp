#include <bits/stdc++.h>

using namespace std;

int findMaxSubarraySum(vector<int> v) {
    int maxSum = v[0];
    int maxCur = v[0];
    for(int i=1; i<v.size(); i++) {
        maxCur = max(v[i], maxCur + v[i]);
        maxSum = max(maxSum, maxCur);
    }
    return maxSum;
}


void maxSubarray(vector<int> v) {
    int maxSubsequenceSum = 0, maxSubarraySum = 0;
    //sum of all positive values
    for(auto a:v)
        if(a>0)
            maxSubsequenceSum += a;
    
    //if no positive values are in the input, no positive sum can be built
    if(maxSubsequenceSum == 0) {
        sort(v.begin(),v.end());
        cout << v[v.size()-1] << " " << v[v.size()-1] << endl;
        return; 
    }

    maxSubarraySum = findMaxSubarraySum(v);

    cout << maxSubarraySum << " " << maxSubsequenceSum << endl;
}

int main()
{
    int q,n;
    cin >> q;
    while(q--) {
        cin >> n;
        vector<int> v (n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        maxSubarray(v);
    }
    return 0;
}
