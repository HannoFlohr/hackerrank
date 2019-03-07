#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string s, int k) {
    int c;
    for(int i=0; i<s.size(); i++) {
        c = (int)s[i];
        if(!( (c>=65 && c<=90) || (c>=97 && c<=122) )  )
            continue;

        c = s[i] - 'a'; 
        if( c>=0 && c<=26 ) { 
            c = (c+k) % 26; 
            s[i] = c + 'a'; 
            continue;
        }
        c = s[i] - 'A';  
        if( c>=0 && c<=26 ) { 
            c = (c+k) % 26; 
            s[i] = c + 'A'; 
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
