#include <bits/stdc++.h>

using namespace std;

int camelcase(string s) {
    int words = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i]-'a' < 0) {
            words++;
            if(i==s.size()-1) break;
        }
        if(i==s.size()-1) words++;
    }
    return words;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
