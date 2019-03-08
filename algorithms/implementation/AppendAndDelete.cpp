#include <bits/stdc++.h>

using namespace std;

string appendAndDelete(string s, string t, int k) {
    if(s==t) return "Yes";
    int i=0; 
    while(s[i]==t[i]) i++;

    if( ( s.length()+t.length()-2*i ) > k ) 
        return "No";
    else if( (s.length()+t.length()-2*i) % 2 == k%2 )
        return "Yes";
    else if( (int)(s.length()+t.length()-k) < 0 )
        return "Yes";
    else 
        return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
