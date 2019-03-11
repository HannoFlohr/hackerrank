#include <bits/stdc++.h>

using namespace std;

long substrCount(int n, string s) {
    long count = 0;
    vector<pair<char,int> > freq;
    int i=0, j=0;

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[j]==s[i]) continue;
            else break;
        } 
        freq.push_back(make_pair(s[i],j-i));
        i = j-1;
    }

    for(i=0; i<freq.size(); i++) {
        count += (freq[i].second + 1) *freq[i].second / 2;
    }
    for(i=1; i<freq.size(); i++) {
        if(freq[i].second == 1 && freq[i-1].first == freq[i+1].first )
            count += min( freq[i-1].second, freq[i+1].second ); 
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
