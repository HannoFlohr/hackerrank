#include <bits/stdc++.h>

using namespace std;

int marsExploration(string s) {
    string sub; 
    int faulty=0;
    for(int i=0; i<s.size(); i+=3) {
        sub = s.substr(i,3); 
        if(sub!="SOS") {
            if(sub[0] != 'S') faulty++;
            if(sub[1] != 'O') faulty++;
            if(sub[2] != 'S') faulty++;
        }
    }
    return faulty;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
