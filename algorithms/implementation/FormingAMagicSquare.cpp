#include <bits/stdc++.h>

using namespace std;

const int magic_squares[8][3][3] = {
    {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
    {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
    {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
    {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}}, 
    {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}}, 
    {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}}, 
    {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}}, 
    {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},  
};

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int min_changes = numeric_limits<int>::max(); 
    int cur_changes;
    for(int square=0; square<8; square++){
        cur_changes = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) 
                cur_changes += abs(s[i][j] - magic_squares[square][i][j] );
        }
        if(cur_changes < min_changes) 
            min_changes = cur_changes;
    }
    return min_changes;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
