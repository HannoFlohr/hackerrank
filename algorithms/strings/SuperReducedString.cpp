#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
    bool deleted = true;
    while(deleted) {
        deleted = false;
        for(int i=0; i<s.length()-1; i++) {
            if(s[i] == s[i+1]) { 
                s.erase(i,2); 
                deleted = true;
                i=i-1;
            }
            if(s.length() == 0) break;
        }
    }
    if(s.length()==0) s = "Empty String";
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
