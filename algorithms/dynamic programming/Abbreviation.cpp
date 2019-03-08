#include <bits/stdc++.h>

using namespace std;

string abbreviation(string a, string b) {
    int n=a.length(), m = b.length();
    if(n==0) {
        if(m==0) return "YES";
        else return "NO"; 
    }
    if(n>0 && m==0) {
        for(auto c:a) {
            if( (int)c>=65 && (int)c<=90 ) return "NO";
        }
        return "YES";
    }

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;


    for(int i=0; i<n; i++) {
        if(a[i]>=65 && a[i]<=90) break;
        else dp[i+1][0] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) { 
            if(a[i-1]==b[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else if(toupper(a[i-1]) == b[j-1])
                    dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            else if(a[i-1]>=65 && a[i-1]<=90)
                dp[i][j]=0;
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][m]==1) return "YES";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
