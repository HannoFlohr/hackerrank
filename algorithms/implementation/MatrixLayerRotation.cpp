#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    int n=matrix.size(), m=matrix[0].size();
    int minN = n, minM = m;
    while(minN > 1 && minM > 1) {
        minN--;
        minM--;
    }
    
    vector<vector<int>> subProblems;
    vector<int> p(0);
    int offset = 0;
    while(offset < n/2 && offset < m/2) {
        for(int i=offset; i<m-offset; i++) 
            p.push_back(matrix[offset][i]);
        for(int j=offset+1; j<n-offset; j++)
            p.push_back(matrix[j][m-1-offset]);
        for(int i=m-2-offset; i>offset; i--) 
            p.push_back(matrix[n-1-offset][i]);
        for(int j=n-1-offset; j>offset; j--)
            p.push_back(matrix[j][offset]);

        subProblems.push_back(p);
        p.clear();
        offset++;
    }

    int elements, cur;
    offset=0;
    for(int a=0; a<subProblems.size(); a++) {
        elements = subProblems[a].size();
        cur = r % elements;

        for(int i=offset; i<m-offset; i++) {
            matrix[offset][i] = subProblems[a][cur];
            if(cur==elements-1) cur = 0;
            else cur++;
        } 
        for(int j=offset+1; j<n-offset; j++) {
            matrix[j][m-1-offset] = subProblems[a][cur];
            if(cur==elements-1) cur = 0;
            else cur++;
        }
        for(int i=m-2-offset; i>offset; i--) {
            matrix[n-1-offset][i] = subProblems[a][cur];
            if(cur==elements-1) cur = 0;
            else cur++;
        }
        for(int j=n-1-offset; j>offset; j--) {
            matrix[j][offset] = subProblems[a][cur];
            if(cur==elements-1) cur = 0;
            else cur++;
        }

        offset++;
    }

    for(int j=0; j<n; j++) {
        for(int i=0; i<m; i++)
            cout << matrix[j][i] << " ";
        cout << endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
