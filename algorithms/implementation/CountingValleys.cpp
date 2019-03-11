#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
    int level = 0, valleys = 0;
    bool inValley = false;
    for(int i=0; i<n; i++) {
        if(s[i]=='D') 
            level--;            
        else 
            level++;
        
        if(level==-1 && !inValley) 
            inValley = true;
        if(level==0 && inValley) {
            inValley = false;
            valleys++; 
        }
    }
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
