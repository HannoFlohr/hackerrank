#include <bits/stdc++.h>

using namespace std;

string happyLadybugs(string b) {
    map<char,int> m;
    for(int i=0; i<b.size(); i++)
        m[ b[i] ]++;
    
    if(m['_']==0) {
        for(int i=0; i<b.size(); i++) {
            if(i==0 && b[i] != b[i+1]) 
                return "NO";
            else if(i==b.size()-1 && b[i] != b[i-1])
                return "NO";
            else if( !(b[i-1] == b[i] || b[i] == b[i+1]) )
                return "NO";
        }
        return "YES";
    }
    else {
        for(auto a : m) {
            if(a.first != '_' && a.second == 1) return "NO";
        }
        return "YES";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
