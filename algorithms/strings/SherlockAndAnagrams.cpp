#include <bits/stdc++.h>

using namespace std;

int sherlockAndAnagrams(string s) {
    int anagrams = 0;

    for(int subLength=1; subLength<s.size(); subLength++) {
        vector<string> subStr (0);
        for(int j=0; j+subLength-1<s.size(); j++) {
            subStr.push_back(s.substr(j,subLength));
        }
        for(int j=0; j<subStr.size(); j++) {
            sort(subStr[j].begin(), subStr[j].end() );
        }
        for(int a=0; a<subStr.size(); a++) {
            for(int b=a+1; b<subStr.size(); b++) {
                if(subStr[a] == subStr[b]) {
                    anagrams++;
                }
            }
        }
    }
    return anagrams;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
