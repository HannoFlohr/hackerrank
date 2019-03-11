#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> merge(const vector<int> &l, const vector<int> &r, long& inversions ) {
    vector<int> m;
    int il=0, ir=0;
    while( !( il>=l.size() || ir>=r.size() ) ) {
            if( l[il] <= r[ir] ) {
                m.push_back(l[il]);
                il++;
            }
            else {
                m.push_back(r[ir]);
                ir++;
                for(int i=il; i<l.size(); i ++) {
                    inversions++; 
                }
            }
    }
    if(il>=l.size() && ir<r.size()) {
            while(ir<r.size()) {
                m.push_back(r[ir]);
                ir++;
            }
    }
    if(ir>=r.size() && il<l.size()) {
            while(il<l.size()) {
                m.push_back(l[il]);
                il++;
            }
    }

    return m;
}

vector<int> merge_sort(const vector<int> &v, long& inversions) {
    if(v.size() <= 1) return v;

    vector<int> left, right;
    int i=0, nx = v.size();
    for( ; i<floor(nx/2); i++) left.push_back(v[i]);
    for( ; i<=nx-1; i++) right.push_back(v[i]);

    left = merge_sort(left, inversions);
    right = merge_sort(right, inversions);

    if(right.size()==0) return left;
    if(left.size()==0) return right; 

    return merge(left, right, inversions);
}

long countInversions(vector<int> arr) {
    long inversions = 0, end=arr.size();
    
    int i=0;
    while(i<arr.size()-1 && (arr[i]<=arr[i+1]) ) {
        i++;
    }
    //already sorted -> return 0 inversions
    if(i+1==arr.size() ) {
        return 0;
    } 

    merge_sort(arr,inversions);
    
    return inversions;
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

        long result = countInversions(arr);

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
