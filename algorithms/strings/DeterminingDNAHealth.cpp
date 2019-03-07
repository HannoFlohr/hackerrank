#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int MAXS = 2 * 1e6;
const int MAXC = 26;

int out [MAXS];
int f [MAXS];
int g [MAXS][MAXC];

int buildMatchingMachine(const vector<string>& genes, int k) { //cout << "k " << k << endl;
    memset(out, 0, sizeof out);
    memset(g, -1, sizeof g);

    int states = 1;
    int currentState, ch;
    for(int i=0; i<k; ++i) { //cout << "i " << i << endl;
        const string& word = genes[i]; //cout << word << endl;
        currentState = 0;
        for(int j=0; j<word.size(); ++j) {
            ch = word[j] - 'a'; //cout << "ch " << ch << endl;

            if(g[currentState][ch] == -1 ) { //cout << "test"<< endl;
                g[currentState][ch] = states++; }

            currentState = g[currentState][ch];
        }

        out[currentState] |= (1<<i);
    }

    for(int c=0; c<MAXC; ++c)
        if(g[0][c] == -1)
            g[0][c] = 0;

 /*   cout << "g: " << endl;
    for(int c=0; c<6; c++) {
        for(int i=0; i<10; i++) cout << g[i][c] << " ";
        cout << endl;
    }
    cout << "out: ";
    for(int i=0; i<10; i++) cout << out[i] << " ";
    cout << endl;
*/
    memset(f, -1, sizeof f);
    queue<int> q;
    for(int c=0; c<MAXC; ++c){ 
        if(g[0][c] != 0) {
            f[g[0][c]] = 0;
            q.push(g[0][c]);
        }
    } 

    //cout << "f:   "; for(int i=0; i<MAXC; i++) cout << f[i] << " "; cout << endl;

    int state, failure, counter = 0, c;
    while(q.size()) { //cout << "count " << counter++ <<endl;
        state = q.front();
        q.pop();

        //for removed state find failure function for all
        //characters for which goto function is not defined
        for(c=0; c<MAXC; c++) { //cout << c << " " << MAXC << " " << (c<=MAXC) << endl;
            if(g[state][c] != -1) {
                failure = f[state];
            
                while(g[failure][c] == -1) { //cout << "test" << endl;
                    failure = f[failure];}

                failure = g[failure][c];
                f[g[state][c]] = failure;

                out[g[state][ch]] |= out[failure];

                q.push(g[state][c]);
            }
        }   
    }
    //cout << "states: " << states << endl;
    return states;
}

int findNextState(int currentState, char nextInput) {
    int answer = currentState;
    int ch = nextInput - 'a';
    while(g[answer][ch] == -1) 
        answer = f[answer];
    return g[answer][ch];
}

long searchWords(const vector<string>& genes, const vector<int>& health, const string& text) { 
    //cout << "checking: " << text << endl;
    buildMatchingMachine(genes, genes.size());

    int currentState = 0;
    long counter = 0L;
    for(int i=0; i<text.size(); ++i) {
        currentState = findNextState(currentState, text[i]);

        if(out[currentState] == 0) {//cout<<"continue"<<endl; 
            continue; }

        for(int j=0; j<genes.size(); ++j) { //cout << "test "<< endl;
            if(out[currentState] & (1<<j)) {
                //cout << "Word " << genes[j] << " found from " << i - genes[j].size() + 1 << " to " << i << endl; 
                counter += health[j]; 
            }
        }
    }
    return counter;
}


long solve(const vector<string>& genes, const vector<int>& health, const int& first, const int& last, const string& d) {
    vector<string> relevant_genes;
    vector<int> relevant_health;
    for(int i=first; i<=last; i++) {
        relevant_genes.push_back(genes[i]);
        relevant_health.push_back(health[i]);
    } 

    return searchWords(relevant_genes,relevant_health,d);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split_string(genes_temp_temp);

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split_string(health_temp_temp);

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long minresult = numeric_limits<long>::max();
    long maxresult = numeric_limits<long>::min();
    long result;
    for (int s_itr = 0; s_itr < s; s_itr++) {
        string firstLastd_temp;
        getline(cin, firstLastd_temp);

        vector<string> firstLastd = split_string(firstLastd_temp);

        int first = stoi(firstLastd[0]);

        int last = stoi(firstLastd[1]);

        string d = firstLastd[2];

        result = solve(genes, health, first, last, d);
        if(result > maxresult) maxresult = result;
        if(result < minresult) minresult = result;
    }

    cout << minresult << " " << maxresult << endl;

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
