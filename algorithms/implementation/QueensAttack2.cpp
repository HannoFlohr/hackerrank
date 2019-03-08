#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    int rowleft = c_q-1;
    int rowright = n-c_q;
    int coldown = r_q-1;
    int colup = n-r_q;
    int rightup = min(rowright,colup);
    int rightdown = min(rowright,coldown);
    int leftup = min(rowleft,colup);
    int leftdown = min(rowleft,coldown);

    int r,c;
    for(auto o : obstacles) {
        r = o[0]; c=o[1];
        if(c==c_q) {
            if(r<r_q) coldown = min(coldown, r_q - r - 1);
            else colup = min(colup, r - r_q - 1); 
        }
        else if(r==r_q) {
            if(c<c_q) rowleft = min(rowleft, c_q - c - 1);
            else rowright = min(rowright, c - c_q - 1);
        }
        else if( abs(r-r_q) == abs(c-c_q) ) {
            if(c>c_q){
                if(r>r_q) rightup = min(rightup, c - c_q - 1);
                else rightdown = min(rightdown, c - c_q -1);
            }
            else {
                if(r>r_q) leftup = min(leftup, c_q - c - 1);
                else leftdown = min(leftdown, c_q - c - 1);
            }
        }
    }

    return rowleft+rowright+coldown+colup+rightdown+rightup+leftdown+leftup;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
