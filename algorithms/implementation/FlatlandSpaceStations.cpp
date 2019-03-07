#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int flatlandSpaceStations(int n, vector<int> c) {
    vector<int> dist (n,numeric_limits<int>::max() );
    sort(c.begin(),c.end());

    int previous, next, j, d;
    for(int i=0; i<c.size(); i++) {
        if(i==0) previous = 0;
        else previous = c[i-1]+1;
        if(i==c.size()-1) next = n-1;
        else next = c[i+1]-1; 

        dist[c[i]] = 0; 
        d = 1;
        for(j=c[i]-1; j>=previous; j--) { 
            if(dist[j]>d) dist[j] = d; 
            d++;
        }
        d = 1;
        for(j=c[i]+1; j<=next; j++) {
            if(dist[j]>d) dist[j] = d;
            d++;
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

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
