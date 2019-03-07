#include <bits/stdc++.h>

using namespace std;

string funnyString(string s) {
    vector<int> differences;
    for(int i=1; i<s.size(); i++) 
        differences.push_back( abs(s[i]-s[i-1]) );
    
    int i=0, j=differences.size()-1;
    while(i<j) {
        if(differences[i] != differences[j]) return "Not Funny";
        i++;
        j--;
    }
    return "Funny";
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
