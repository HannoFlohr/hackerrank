#include <bits/stdc++.h>

using namespace std;

bool compare(string s1, string s2) {
    if(s1.size() > s2.size()) 
        return false;
    else if(s2.size() > s1.size())
        return true;
    else {
        for(int i=0; i<s1.size(); i++) {
            if(s1[i]-'0' == s2[i]-'0') continue;
            if(s1[i]-'0' < s2[i]-'0') return true;
            else return false;
        }
    }
    return false;
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
