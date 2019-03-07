#include <bits/stdc++.h>

using namespace std;

string encryption(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    int row = round( sqrt(s.size() ) ); 
    int column;
    if(row>=sqrt(s.size())) column = row;
    else column = row+1;
    string enc = "";
    for(int j=0; j<column; ++j) {
        for(int i=j; i<s.size(); i+=column) 
            enc += s[i];
        enc += " ";
    }
    return enc;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
