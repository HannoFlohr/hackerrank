#include <bits/stdc++.h>

using namespace std;

string gameOfThrones(string s) {
    vector<int> freq (26,0);
    for(auto c: s)
        freq[c-'a']++;
    int odd=0;
    for(auto f:freq)
        if(f%2 != 0) odd++;
    return (odd>1) ? "NO" : "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
