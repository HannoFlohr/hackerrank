#include <bits/stdc++.h>

using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector<bool> u (1e7);
    int cur, factor=1, w, last=0;
    for(int i=0; i<s.size(); i++) {
        cur = s[i] - 'a' + 1;
        if(cur==last) factor++;
        else factor = 1;
        last = cur;
        w = cur * factor;
        u[w] = true;
    }

    vector<string> results (0);
    for(auto q : queries) {
        if(u[q] == true) results.push_back("Yes");
        else results.push_back("No");
    }
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
