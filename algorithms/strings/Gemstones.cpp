#include <bits/stdc++.h>

using namespace std;

int gemstones(vector<string> arr) {
    int freq[26] = {0};
    int gems = 0;
    char c;
    for(int i=0; i<arr.size(); i++) {
        sort(arr[i].begin(), arr[i].end());
        arr[i].erase(unique(arr[i].begin(),arr[i].end()), arr[i].end() );
    
        for(int j=0; j<arr[i].size(); j++) {
            c = arr[i].at(j);
            freq[c-'a']++;
            if(freq[c-'a'] == arr.size() ) gems++;
        }
    }
    return gems;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
