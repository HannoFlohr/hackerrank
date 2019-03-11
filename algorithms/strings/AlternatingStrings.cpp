#include <bits/stdc++.h>

using namespace std;

char switchChar(const char &c) {
    if(c=='A') return 'B';
    else return 'A';
}

int alternatingCharacters(string s) {
    int deletions = 0;
    char cur, search;
    cur = s[0];
    search = switchChar(cur);
    for(int i=1; i<s.size(); i++) {
        if(s[i] != search) 
            deletions++;
        else 
             search = switchChar(search);
    }

    return deletions;
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

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
