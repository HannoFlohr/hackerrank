#include <bits/stdc++.h>

using namespace std;

string hackerrankInString(string s) {
    const string hr = "hackerrank";
    int j=0;
    char c;
    for(int i=0; i<hr.size(); i++) {
        c = hr[i]; 
        while(s[j] != c) { 
            j++; 
            if(j==s.size()) {
                if(i<hr.size()-1) 
                    return "NO";
                break;
            }
        }

        if(i==hr.size()-1) 
            return "YES";

        j++;
        if(j>=s.size()) break;
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
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
