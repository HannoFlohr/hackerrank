#include <bits/stdc++.h>

using namespace std;

int stringConstruction(string s) {
    vector<bool> subs (26,0);
    int cost = 0;
    for(auto c:s) {
        if( !subs[c-'a'] ) cost++;
        subs[c-'a'] = true; 
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
