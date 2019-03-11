#include <bits/stdc++.h>

using namespace std;

int commonChild(string s1, string s2) {
    vector<vector<int> > grid (s1.length()+1,vector<int>(s2.length()+1));

    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1] == s2[j-1])
                grid[i][j] = grid[i-1][j-1] + 1;
            else 
                grid[i][j] = max( grid[i][j-1], grid[i-1][j] );
        }
        
    }

    return grid[s1.length()][s2.length()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
