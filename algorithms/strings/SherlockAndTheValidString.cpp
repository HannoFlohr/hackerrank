#include <bits/stdc++.h>

using namespace std;

string isValid(string s) {
    map<char,int> m;
    for(auto c : s) m[c]++;

    bool valid = true, oneFound = false;
    int occur = -1;
    for(auto i : m) {
        if(occur==-1) occur = i.second;
        if(i.second != occur) {
            if(!oneFound) 
                oneFound=true;
            else {
                valid = false;
                break;
            }
        }
    }  
    
    if(valid) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
