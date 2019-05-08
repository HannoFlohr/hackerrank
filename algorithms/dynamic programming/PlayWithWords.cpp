#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    const int length = s.length();
    int x;

    vector<vector<int>> dp (length+1);
    for(int i=length; i>0; i--) {
        vector<int> v (i, 0);
        dp[length-i] = v;
    }
    // i = length of subsequence; j = start position of subsequence
	/*
		dp(i, j) = 1 if i is 1
		dp(i, j) = 2 + dp (i - 2, j + 1) if first and last characters are equal.
		dp(i, j) = max(dp(i - 1, j), dp(i - 1, j + 1)) otherwise 
	*/
    for(int i=0; i<=length; i++) {
        for(int j=0; j<=length; j++) {
            if(i+j == length) 
                break;
            if(i == 0) 
                dp[i][j] = 1;
            else if(i == 1) {
                if(s[j] == s[j+i])
                    dp[i][j] = 2;
                else 
                    dp[i][j] = 1;
            } 
            else {
                if(s[j] == s[j+i])
                    x = 2;
                else
                    x = 0;

                dp[i][j] = max( dp[i-2][j+1] + x, dp[i-1][j] );
                dp[i][j] = max( dp[i][j], dp[i-1][j+1] );
            }
        }
        
        /*for(auto a:dp) {
            for(auto b:a) cout << b << " ";
            cout << endl;
        }*/
    }

    int result = 0;
    for(int i=0; i<length-1; i++) 
        result = max(result, dp[i][0] * dp[length-i-2][i+1]);

    cout << result << endl;

    return 0;
}
