#include <bits/stdc++.h>

using namespace std;

string biggerIsGreater(string w) {
    for(int i=w.size(); i>0; i--) {
        if(w[i] <= w[i-1]) continue;
        next_permutation(w.begin(),w.end());
        return w;
    }
    return "no answer";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
