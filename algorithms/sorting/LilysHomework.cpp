#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int solve (vector<int> arr, bool ascending) {
    map<int,int> m;
    for(int i=0; i<arr.size(); i++) 
        m[arr[i]] = i;

    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());

    int temp, index, swaps = 0;
    for(int i=0; i<arr.size(); i++) {
        if( arr[i] != sorted[i] ) {
            swaps++;
            index = m[ sorted[i] ];
            m[ arr[i] ] = m[ sorted[i] ];
            temp = arr[i];
            arr[i] = sorted[i];
            arr[index] = temp;
        }
    }
    return swaps;
}

int lilysHomework(vector<int> arr) {
    int ascending = solve(arr, true);
    reverse(arr.begin(),arr.end());
    int descending = solve(arr, false);
    return min(ascending,descending);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
