#include <bits/stdc++.h>
using namespace std;

const int MAXSTRINGLENGTH = 1500;
int dp [MAXSTRINGLENGTH+2][MAXSTRINGLENGTH+2];
int k, length;

// check if a value <= 'k' of unmatched characters exists 
// by computing the difference between each index from 'mid' to 'length'
bool check(int mid) {
    int cur;
    for(int i=mid; i<=length; i++) 
        for(int j=mid; j<=length; j++) {
            cur = dp[i][j] - dp[i-mid][j-mid];
            if(cur <= k) 
                return true;
        }
    
    return false;
}

int substringDiff(const string &s1, const string &s2) {
    length = s1.size();

    // set LCS in dp array
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            if(s1[i] == s2[j])
                dp[i+1][j+1] = dp[i][j];
            else
                dp[i+1][j+1] = dp[i][j] + 1;
        }
    }
    
    int low = 0, mid, high = length;
    //find maximum length by binary search
    while(low < high) {
        mid = (low + high + 1) >> 1;
        if( check(mid) ) 
            low = mid;
        else 
            high = mid - 1;
    }

    return low;
}

int main()
{
    int t;
    string s1, s2;
    cin >> t;
    while(t--) {
        cin >> k >> s1 >> s2;
        cout << substringDiff(s1, s2) << endl;
    }

    return 0;
}
