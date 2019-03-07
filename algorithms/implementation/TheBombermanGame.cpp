#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void reverseGrid(const vector<string>& grid, vector<string>& helper, const int& n, const int& m) {
    for(int j=0; j<n; j++) 
        for(int i=0; i<m; i++) {
            if(grid[j][i]=='O')
                helper[j][i] = '.';
            else { 
                if( (j>0 && grid[j-1][i]=='O') ||
                    (j<n-1 && grid[j+1][i]=='O') ||
                    (i>0 && grid[j][i-1]=='O') ||
                    (i<m-1 && grid[j][i+1]=='O') ) 
                        helper[j][i] = '.';
                else 
                    helper[j][i] = 'O';
            }
        }
}

vector<string> bomberMan(int s, vector<string> grid) {
    if(s == 1) 
        return grid;
    int n = grid.size(), m = grid[0].size();
    if(s%2 == 0) {
        for(int j=0; j<n; j++) 
            for(int i=0; i<m; i++)
                grid[j][i] = 'O';
        return grid;
    }

    string str = "";
    for(int i=0; i<m; i++) str += ".";
    vector<string> helper = vector<string>(n,str);
    reverseGrid(grid, helper, n, m);
    if(s%4 == 3) return helper;

    reverseGrid(helper, grid, n, m);
    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
