#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void leftNeighbors(const int& i, const int& min_height, const vector<int>& h, queue<int>& q) {
    if(i>=0 && h[i]>=min_height) {
        q.push(i); 
        leftNeighbors(i-1,min_height,h,q);
    }  
}

void rightNeighbors(const int& i, const int& min_height, const vector<int>& h, queue<int>& q) {
    if(i<h.size() && h[i]>=min_height) {
        q.push(i); 
        rightNeighbors(i+1,min_height,h,q);
    }  
}

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    long largest_rectangle_size = numeric_limits<long>::min();
    long current_rectangle_size;
    queue<int> q;
    
    for(int i=0; i<h.size(); i++) { 
        current_rectangle_size = 0;
        q.push(i); 
        leftNeighbors(i-1,h[i],h,q);
        rightNeighbors(i+1,h[i],h,q);
        
        while(!q.empty()) {
            current_rectangle_size += 1;
            q.pop();
        }

        current_rectangle_size *= h[i];

        if(largest_rectangle_size < current_rectangle_size) 
            largest_rectangle_size = current_rectangle_size;
    }
    return largest_rectangle_size;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

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
