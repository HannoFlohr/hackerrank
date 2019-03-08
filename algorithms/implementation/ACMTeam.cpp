#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> acmTeam(vector<string> topic) {
    int max=-1, teams=0, cur;
    string s1, s2, bit_or;
    for(int i=0; i<topic.size(); i++) {
        s1 = topic[i];
        for(int j=i+1; j<topic.size(); j++) {
            s2 = topic[j];
            cur = 0;
            for(int k=0; k<s1.size(); k++) {
                if( (s1[k] | s2[k]) == 49 ) { 
                    cur++;
                }
            }
            if(cur>max) { 
                max = cur;
                teams=1;
            }
            else if(cur==max) 
                teams++;
        }

    }
    vector<int> result = {max, teams};
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

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
