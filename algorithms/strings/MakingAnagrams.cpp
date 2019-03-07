#include <bits/stdc++.h>

using namespace std;

int makingAnagrams(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    vector<int> freq1 (26,0);
    vector<int> freq2 (26,0);
    for(int i=0; i<n1; i++) freq1[s1[i]-'a']++;
    for(int i=0; i<n2; i++) freq2[s2[i]-'a']++;
    
    int diff=0;
    for(int i=0; i<26; i++) 
        if(freq1[i] != freq2[i]) diff += abs(freq1[i] - freq2[i]);
    return diff;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
