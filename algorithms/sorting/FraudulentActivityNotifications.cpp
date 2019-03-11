#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int getMedianTimesTwo(const vector<int> &v) {
    int d= v.size();
    if(d%2==0) 
        return v[d/2] + v[(d/2)-1];
    else
        return 2 * v[ floor(d/2) ];
}

void countingsort(vector<int> * A) {
    int freq [201] = {0};
    for(int j=0; j<A->size(); j++) 
        freq[ A->at(j) ]++;
    
    A->clear();
    for(int i=0; i<201; i++) {
        if(freq[i]>0) {
            for(int j=0; j<freq[i]; j++) {
                A->push_back(i);
            }
        } 
    }
}

int activityNotifications(vector<int> expenditure, int d) {
    unsigned int notifications = 0, medianTwo;

    vector<int> lastExp (expenditure.begin(), expenditure.begin()+d);
    //counting sort on the last expenditures
    countingsort(&lastExp);
    
    for(int i=d; i<expenditure.size(); i++) {
        if(i==d) {
            medianTwo = getMedianTimesTwo(lastExp); 
        } 
        else {
            //remove the oldest expenditure
            auto pos = lower_bound(lastExp.begin(), lastExp.end(), expenditure[i-d-1]);
            if(pos==lastExp.end()) {
                cout << "impossible"<<endl; exit(1);
            }
            lastExp.erase(pos);
            // add next expenditure
            lastExp.insert( upper_bound(lastExp.begin(), lastExp.end(), expenditure[i-1]), expenditure[i-1] );

            medianTwo = getMedianTimesTwo(lastExp);
        }
        
        if(expenditure[i] >= medianTwo ) notifications++; 
    }
    return notifications;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
