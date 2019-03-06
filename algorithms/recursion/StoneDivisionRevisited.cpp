#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

map<long,long> results;

// Complete the stoneDivision function below.
long stoneDivision(long n, vector<long> s) { 
    if(n<2) return 0;

    if( results[n] != 0 ) return results[n]; 

    long sum, maxmoves = 0;
    for(auto a : s) {
        if(n%a!=0 || n<=a) continue;

        sum = 1 + (n/a) * stoneDivision(a,s);
        maxmoves = max(maxmoves,sum);
    }

    results[n] = maxmoves;

    return maxmoves;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        long n = stol(nm[0]);

        int m = stoi(nm[1]);

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split_string(s_temp_temp);

        vector<long> s(m);

        for (int i = 0; i < m; i++) {
            long s_item = stol(s_temp[i]);

            s[i] = s_item;
        }

        results.clear();
        long result = stoneDivision(n, s);

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
