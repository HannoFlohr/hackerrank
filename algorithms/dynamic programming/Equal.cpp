#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int equal(vector<int> arr) {
    int min_value = *min_element(arr.begin(),arr.end());
    int cur, reducebyfive=0;
    for(auto& a : arr) {
        cur = floor((a-min_value)/5.0);
        a -= 5*floor((a-min_value)/5.0);
        reducebyfive += cur;
    }

    min_value = *min_element(arr.begin(),arr.end());
    //only values 0...4 in array at this point
    vector<int> freq (5);
    for(int i=0; i<arr.size(); i++)
        freq[ arr[i]-min_value ]++;

    int actions;
    //case min
    actions = (freq[1] + freq[2]) +
              2 * (freq[3]+ freq[4]);  

    //case min-1
    cur = (freq[0] + freq[1] + freq[4]) +
          2 * (freq[2] + freq[3]);
    actions = min(actions, cur);

    //case min-2
    cur = (freq[0] + freq[3]) +
          2 * (freq[1] + freq[2] + freq[4]);
    actions = min(actions, cur);
    
    return reducebyfive+actions;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        int result = equal(arr);

        fout << result << "\n";
    }

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
