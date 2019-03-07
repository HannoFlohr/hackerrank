#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool checkGrids(const vector<vector<int>>& g, const vector<vector<int>>& s, int x, int y) {
    for(int j=0; j<s[0].size(); j++) {
        for(int i=0; i<s.size(); i++) 
            if(g[x+i][y+j] != s[i][j]) return false;
    }
    return true;
}

string gridSearch(vector<string> G, vector<string> P, int R, int C, int r, int c) {
    vector<vector<int>> grid (C, vector<int>(R,0));
    vector<vector<int>> search (c, vector<int>(r,0));

    string g;
    for(int j=0; j<R; j++) {
        g = G[j];
        for(int i=0; i<C; i++) 
            grid[i][j] = g[i] - '0';
    }
    for(int j=0; j<r; j++) {
        g = P[j];
        for(int i=0; i<c; i++) 
            search[i][j] = g[i] - '0';
    }

    int first = search[0][0];
    for(int j=0; j<=R-r; j++) {
        for(int i=0; i<=C-c; i++) {
            if(grid[i][j] != first) continue;

            if(checkGrids(grid,search,i,j)) return "YES";
        }

    }  
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P, R, C, r, c);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
