#include <bits/stdc++.h>

using namespace std;

bool compare(const char& c1, const char& c2) {
    return (c1-'a' <= c2-'a');
}

string gridChallenge(vector<string> grid) { 
    int n=grid.size();
    int m=grid[0].size();
    for(auto& s : grid) sort(s.begin(),s.end()); 

    for(int i=0; i<m; i++)  
        for(int j=1; j<n; j++)  
            if(!compare( grid[j-1].at(i), grid[j].at(i) ) ) 
                return "NO";  
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
