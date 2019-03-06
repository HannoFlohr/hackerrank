#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
/*long maximumSum(vector<long> a, long m) {
    long n = a.size();
    
    //compute prefix sum for each index and sort it
    vector<pair<long,long>> prefix (n);
    prefix[0].first = a[0] % m;
    prefix[0].second = 0;
    for(int i=1; i<n; i++) {
        prefix[i].first = (a[i] % m + prefix[i-1].first) % m;
        prefix[i].second = i; 
    } 
    sort(prefix.begin(),prefix.end());

    long maxPrefix = prefix[n-1].first;
    long minPrefix = numeric_limits<long>::max();
    for(int i=0; i<n-1; i++) 
        if(prefix[i].second > prefix[i+1].second) 
            minPrefix = min(minPrefix, (prefix[i+1].first - prefix[i].first) );
    
    return max(maxPrefix, m-minPrefix);
}*/

long maximumSum(vector<long> a, long m) {
    long n = a.size();
    long prefix=0, maxMod=0;
    set<long> s;
    set<long>::iterator it;
    s.insert(0);
    for(int i=0; i<n; i++) {
        prefix = (prefix + a[i] % m) % m;
        maxMod = max(maxMod,prefix);
        it = s.lower_bound(prefix+1);
        if(it != s.end()) 
            maxMod = max(maxMod, prefix - (*it) + m);
        s.insert(prefix);
    }
    return maxMod;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        long m = stol(nm[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split_string(a_temp_temp);

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

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
