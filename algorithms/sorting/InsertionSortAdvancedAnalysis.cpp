#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long merge(vector<int>& a, vector<int>& b) {
    vector<int> merged;
    long long i=0, j=0, swaps=0;
    while(! (i==a.size() && j==b.size()) ) {
        if(i==a.size()) {
            while(j<b.size()) {
                merged.push_back(b[j]);
                j++;
            }
            break;
        }
        if(j==b.size()) {
            while(i<a.size()) {
                merged.push_back(a[i]);
                i++;
            }
            break;
        }

        if(a[i] <= b[j]) {
            merged.push_back(a[i]);
            i++;
        }
        else {
            merged.push_back(b[j]);
            j++;
            swaps += (long long)(a.size()-i);
        }
        
    }
    a.clear();
    a = merged;
    return swaps;
}

long long divideAndConquer(vector<int>& a) {
    if(a.size() == 1) return 0;
    if(a.size() == 2) {
        if(a[0]<=a[1]) return 0;
        else {
            swap(a[0],a[1]);
            return 1;
        }
    }
    
    size_t half = a.size()/2;
    vector<int> v1 (a.begin(), a.begin() + half);
    vector<int> v2 (a.begin() + half, a.end());

    long long left, right, merged;
    left = divideAndConquer(v1);
    right = divideAndConquer(v2);
    merged = merge(v1,v2);
    a = v1;
    return (left+right+merged);
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

        long long result = divideAndConquer(arr);

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
