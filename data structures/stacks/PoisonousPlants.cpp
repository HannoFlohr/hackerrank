#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*void out(vector<list<int> > v) {
    cout << "stacks:"<<endl;
    for(auto a:v) { 
        for(auto b:a) cout << b << " ";
        cout << endl;
    }
}*/

vector<list<int>* > stacks;

void oneDay() {
    for(int i=1; i<stacks.size(); i++) { 
        stacks[i]->pop_front();
        if(stacks[i]->size()==0) {
            stacks.erase(stacks.begin()+i);
            i--;
        }
    }
    for(int i=0; i<stacks.size()-1; i++) {
        if(stacks[i]->back() >= stacks[i+1]->front() ) {
            stacks[i+1]->splice(stacks[i+1]->begin() , *stacks[i]);
            stacks.erase(stacks.begin()+i);
            i--;
        }
    }
    
}

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    int count_days = 0;
    for(int i=0; i<p.size(); i++) {
        list<int> * curStack = new list<int>();
        curStack->push_back(p[i]);
        while(p[i]>=p[i+1]) {
            if(i+1<p.size()) curStack->push_back(p[i+1]);
            i++;
        }
        stacks.push_back(curStack);
    }
    
    while(stacks.size()>1) {
        count_days++;
        oneDay();
    }
    return count_days;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    int result = poisonousPlants(p);

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
