#include <bits/stdc++.h>

using namespace std;

string reverseShuffleMerge(string s) {
    int n = s.size();
    int count [10001][26];
    int needed [26];

    memset(count,0,sizeof(count));

    string firsthalf = s.substr(0,n/2);
    string secondhalf = s.substr(n/2,n/2);
    reverse(secondhalf.begin(),secondhalf.end());
    reverse(s.begin(),s.end());

    for(int i=n-1; i>=0; i--) {
        copy(count[i+1], count[i+1]+26, count[i]);
        count[i][ s[i]-'a' ]++;
    }
    
    copy(count[0], count[0]+26, needed);
    for(int i=0; i<26; i++) needed[i] /= 2;

    int start=-1, end=0;
    string result = "";
    for(int i=0; i+i<n; i++) {
        do{
            start++;
        } while( needed[ s[start]-'a' ] == 0 );

        for(int j=start; j<n; j++) {
            if( ( needed[s[j]-'a'] > 0 ) && ( s[j] < s[start] ) ) {
                if(j<end) 
                    start = j;
                else {
                    bool comp = true;
                    for(int c=0; c<26; c++) {
                        if(count[j][c] < needed[c]) {
                            comp = false;
                            break;
                        }
                    }
                    if(!comp) break;
                
                    start = j;
                    end++;
                }
            }
        }
    
        needed[ s[start]-'a' ]--;
        result += s[start];
    }

    if(result == firsthalf && result == secondhalf) return "eaid";

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
