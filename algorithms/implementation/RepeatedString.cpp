#include <bits/stdc++.h>

using namespace std;

long repeatedString(string s, long n) {
    if(s.length()==1 && s[0]=='a')
            return n;
    return ((n/s.length()) * count(s.begin(), s.end(), 'a')) +
            count(s.begin(), s.begin() + n%s.size(), 'a');
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
