#include <bits/stdc++.h>

using namespace std;

int anagram(string s) {
    int n = s.size();
    if(n%2 == 1) return -1;
    string s1,s2;
    s1 = s.substr(0, n/2);
    s2 = s.substr(n/2, n/2);

    vector<int> freq1 (26,0);
    vector<int> freq2 (26,0);
    for(int i=0; i<n/2; i++) {
        freq1[s1[i]-'a']++;
        freq2[s2[i]-'a']++;
    }
    
    int diff=0;
    for(int i=0; i<26; i++) 
        if(freq1[i] > freq2[i]) diff += (freq1[i] - freq2[i]);
    return diff;
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
