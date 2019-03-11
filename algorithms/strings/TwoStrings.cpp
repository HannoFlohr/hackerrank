#include <bits/stdc++.h>

using namespace std;

string twoStrings(string s1, string s2) {
    int maxLength;
    if(s1.size()>=s2.size()) maxLength = s1.size();
    else maxLength = s2.size();

    string s = "";
    for(int subLen=1; subLen<=maxLength; subLen++) {
        if(subLen == 1) {
            unordered_map<char,int> m;
            for(auto s : s1) m[s]++;
            //for(auto n : m) cout << n.first << " " << n.second << endl;
            for(auto s : s2) {
                if(m[s]>0) return "YES";
            }
        }
        
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
