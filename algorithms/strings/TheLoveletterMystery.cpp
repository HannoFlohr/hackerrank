#include <bits/stdc++.h>

using namespace std;

int theLoveLetterMystery(string s) {
    int low=0; int high=s.length()-1;
    int counter = 0;
    while(low<high) {
        if(s[low]!=s[high]) counter += abs( (s[low] - 'a') - (s[high] - 'a') );
        low++;
        high--;
    }
    return counter;
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

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
