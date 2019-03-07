#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Range {
public:
    unsigned long long start;
    unsigned long long end;
    Range() {}
    Range(unsigned long long s, unsigned long long e) : start(s), end(e) {}

    bool overlaps(Range* r1, Range* r2){
        if( (r1->end >= r2->start && r1->start <= r2->start) || 
            (r2->end >= r1->start && r2->start <= r1->start) ) {
            r1->start = min(r1->start, r2->start);
            r1->end = max(r1->end, r2->end);
            return true;
        } 
        return false;
    } 
};

bool compare(const vector<int>& t1, const vector<int>& t2) {
    return t1[0] < t2[0];
}

// Complete the gridlandMetro function below.
unsigned long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    sort(track.begin(),track.end());
    unsigned long long cur, min, max;
    unsigned long long result = (unsigned long long)n * (unsigned long long)m;
    vector<Range*> ranges;
    Range* r; 
    Range* r2;
    for(int i=0; i<track.size(); i++) {
        cur = track[i][0];
        r = new Range(track[i][1],track[i][2]);
        ranges.push_back(r);
        while(i<track.size() && track[i][0] == cur) {
            r2 = new Range(track[i][1],track[i][2]);
            if( !r->overlaps(r,r2) ) ranges.push_back(r2);
            i++;
        }
        if( !ranges.empty() ) 
            for(int i=0; i<ranges.size(); i++)
                result -= ranges[i]->end - ranges[i]->start + (unsigned long long)1;

        i--;
        ranges.clear();
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    vector<vector<int>> track(k);
    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    unsigned long long result = gridlandMetro(n, m, k, track);

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
