#include <bits/stdc++.h>

using namespace std;

string pangrams(string s) {
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    int freq [26] = {0};
    for(int i=0; i<s.size(); i++) 
        freq[ s[i] - 'a' ]++;

    for(int i=0; i<26; i++) { cout << freq[i] << " ";
        if(freq[i] == 0) return "not pangram"; }

    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
