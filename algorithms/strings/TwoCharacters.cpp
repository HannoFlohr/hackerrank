#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int alternate(string s) {
    int letters [26] = {0};
    for(auto c : s) letters[c-'a']++;

    vector<char> toCheck;
    for(int i=0; i<26; i++) 
        if(letters[i]>0) toCheck.push_back(i+'a');

    string cur;
    int max_length = 0;
    for(int i=0; i<toCheck.size(); i++) {
        for(int j=i+1; j<toCheck.size(); j++) { 
            cur = s;
            for(int k=0; k<toCheck.size(); k++) {
                if(k==i || k== j) continue;
                cur.erase(remove(cur.begin(), cur.end(), toCheck[k]), cur.end());
            }
            for(int i=1; i<cur.size(); i++) {
                if(cur[i-1]==cur[i]) break;
                if(i==cur.size()-1) {
                    if(cur.size()>max_length) max_length=cur.size();
                }
            }
        }
    }
    return max_length;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
