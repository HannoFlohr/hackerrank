#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int addWalls(const int& i, const int& j, const int& H, const int& W, const vector<vector<int>>& A) {
    int value = A[j][i];
    int sameHeight;
    int additionalWalls = 0;
    for(int v=2; v<=value; v++) {
        sameHeight = 0;
        if(i>0 && A[j][i-1] >= v) sameHeight++; 
        if(i<W-1 && A[j][i+1] >= v) sameHeight++;
        if(j>0 && A[j-1][i] >= v) sameHeight++;
        if(j<H-1 && A[j+1][i] >= v) sameHeight++;
        
        additionalWalls += 4 - sameHeight; 
    }
    return additionalWalls;
}

int surfaceArea(vector<vector<int>> A) {
    int H = A.size();
    int W = A[0].size();
    //minimum surface for all cells having height 1
    int surface = 2 * ( H * W) + 2 * (H + W); 

    for(int j=0; j<H; j++) {
        for(int i=0; i<W; i++) {
            if(A[j][i]==1) continue;
            surface += addWalls(i,j,H,W,A);
        }
    }
    return surface;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string HW_temp;
    getline(cin, HW_temp);

    vector<string> HW = split_string(HW_temp);

    int H = stoi(HW[0]);

    int W = stoi(HW[1]);

    vector<vector<int>> A(H);
    for (int i = 0; i < H; i++) {
        A[i].resize(W);

        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = surfaceArea(A);

    fout << result << "\n";

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
