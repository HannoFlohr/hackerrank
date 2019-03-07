#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

string highestValuePalindrome(string s, int n, int k) {
    if(n==1) return "9";
    if(k>=n) {
        for(int i=0; i<s.size(); i++) 
            s[i] = '9';
            return s;
    }
    if(s.size()<n) {
        int dif = n-s.size();
        while(dif--) s = "0"+s;
    }

    vector<bool> changed (n,false);

    int first=0, last=s.size()-1; 
    int changes=0;
    while(first < last) {
        if(s[first] != s[last]) { 
            if(s[first] < s[last]) {
                s[first] = s[last];
                changes++;
                changed[first] = true;
            }
            else {
                s[last] = s[first];
                changes++;
                changed[last] = true;
            }
            if(changes > k) return "-1"; 
        }
        first++;
        last--;
    }

    if(changes < k) {
        k -= changes;
        first=0, last=s.size()-1;
        while(k>0 && first<last) { 
            if(s[first] != '9') {
                if(k>1 || (changed[first] || changed[last]) ) {
                    s[first] = '9';
                    if(!changed[first]) k--;
                    s[last] = '9';
                    if(!changed[last]) k--;
                }
            }
            first++;
            last--;
        }
        if(k>=1 && s.size()%2==1) { 
            s[n/2] = '9';
            k--;
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
