#include<bits/stdc++.h>
using namespace std;

bool has_k_islands(string s, const int &k, const string &sstr) {
    set<char> chars;
    for(int i=0; i<sstr.length(); i++) 
        chars.insert(sstr[i]);
        
    for(int i=0; i<s.length(); i++)
        if(chars.find(s[i]) != chars.end())
            s[i] = 'X';
            
    int islands = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'X') {
            islands++;
            while(s[i] == 'X' && i<s.length())
                i++;
            i--;
        }
    }
    
    cerr<<sstr<<" "<<islands<<endl;
    
    return (islands == k ? true : false);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    string s, sstr;
    int k, i, j;
    cin >> s >> k;
    
    int max_substring_length = floor(s.length() / k);
    
    set<string> substrings;
    for(i=1; i<=max_substring_length; i++) 
        for(j=0; j<s.length()-k+1; j++) {
            sstr = s.substr(j, i);
            substrings.insert(sstr);
        }
    
    int counter = 0;
    for(auto it=substrings.begin(); it!=substrings.end(); it++) 
        if( has_k_islands(s, k, *it) )
            counter++;
    
    cout << counter << endl;
    
    return 0;
}
//https://www.hackerrank.com/challenges/letter-islands/problem