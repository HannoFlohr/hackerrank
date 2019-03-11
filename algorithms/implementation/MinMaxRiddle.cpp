#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    int n=arr.size();
    vector<long> max_of_mins(n,0);
    vector<int> count(n,0);

    deque<long> values;
    deque<int> indexes;
    indexes.push_front(-1);

    //count number of greater elements to the left
    for(int i=0; i<n; i++) { 
        while(!values.empty() && values.front() >= arr[i]) {
            values.pop_front();
            indexes.pop_front();
        }
        
        count[i] = i - indexes.front() - 1; 
        values.push_front(arr[i]);
        indexes.push_front(i);
    }

    values.clear();
    indexes.clear();
    indexes.push_front(n);
    //count number of greater elements to the right
    for(int i=n-1; i>=0; i--) {
        while(!values.empty() && values.front() >= arr[i] ) {
            values.pop_front();
            indexes.pop_front();
        }
        count[i] += indexes.front() - 1 - i;
        values.push_front(arr[i]);
        indexes.push_front(i);
    }

    //set results in max_of_mins
    for(int i=0; i<n; i++) 
        max_of_mins[ count[i] ] = max ( max_of_mins[count[i]] , arr[i] );
    for(int i=n-2; i>=0; i--) 
        max_of_mins[i] = max(max_of_mins[i],max_of_mins[i+1]);

    return max_of_mins;
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

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<long> res = riddle(arr);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
