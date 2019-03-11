#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int hasCost(const vector<int> &v, const int &search) {
    int left = 0, right = v.size()-1, mid;

    while(left<right) {
        mid = left + (right-left) / 2;

        if(v[mid]==search) 
            return mid;
        else if(search < v[mid]) 
            right = mid-1;
        else   
            left = mid+1;
    }

    return -1;
}

void whatFlavors(vector<int> cost, int money) {
    // flavor#,cost
    map<int,int> flavors;
    for(int i=0; i<cost.size(); i++) {
        flavors[ cost[i] ] = i;
    }

    int sunny, johnny, i=0;
    for(auto sunny : cost) {
        johnny = money - sunny;
        if( flavors.find(johnny) != flavors.end() && flavors[johnny]!=i ) {
            break;
        }
        i++;
    }

    cout << min(i+1,flavors[johnny]+1) << " " << max(i+1,flavors[johnny]+1) << endl;
} 

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
