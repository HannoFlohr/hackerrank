#include <bits/stdc++.h>

using namespace std;

int beautifulBinaryString(string b) {
    int counter=0;
    for(int i=0; i<b.length()-2; i++) {
        if(b[i]=='0' && b[i+1]=='1' && b[i+2]=='0') {
            b[i+2] = '1';
            counter++;
        }
    }
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
