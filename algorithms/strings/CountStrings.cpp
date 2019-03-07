#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<vector<pair<int,int>>> transitionGraph;
vector<pair<int,int>> DFA;
vector<int> epsilon;
vector<char> visited;
vector<vector<int>> matrix;
vector<int> finalstate;

void buildNFA(string& s, int& index, int inc, int out) {
    if(s[index] == 'a') {
        transitionGraph[inc].push_back({out,1});
        index++;
        return;
    }
    if(s[index] == 'b') {
        transitionGraph[inc].push_back({out,2});
        index++;
        return;
    }

    int m1, m2;
    m1 = transitionGraph.size();
    transitionGraph.push_back(vector<pair<int,int>>());
    m2 = transitionGraph.size();
    transitionGraph.push_back(vector<pair<int,int>>());

    index++;
    buildNFA(s,index,m1,m2);

    if(s[index] == '*') {
        transitionGraph[m2].push_back({m1, 0});
        transitionGraph[inc].push_back({m2, 0});
        transitionGraph[m2].push_back({out, 0});
        index += 2;
        return;
    }
    if(s[index] == '|') {
        transitionGraph[inc].push_back({m1, 0});
        transitionGraph[m2].push_back({out, 0});
        index++;
        buildNFA(s,index,m1,m2);
        index++;
        return;
    }

    transitionGraph[inc].push_back({m1, 0});
    buildNFA(s,index,m2,out);
    index++;
}

void dfs_e(int n) {
    if(visited[n]) return;
    visited[n] = true;
    epsilon.push_back(n);
    for(pair<int,int> e : transitionGraph[n]) {
        if(e.second == 0) dfs_e(e.first);
    }
}

void dfs(vector<int> state, int t) {
    visited =vector<char>(transitionGraph.size(),false);
    epsilon.clear();
    for(int s : state) {
        for(pair<int,int> a : transitionGraph[s])
            if(a.second == t)
                dfs_e(a.first);
    }
}

void convertToDFA() {
    int nodes = 0;
    map<vector<int>, int> e;
    vector<vector<int>> states;
    
    DFA.clear();
    DFA.push_back({-1,-1});
    epsilon.clear();
    
    visited =vector<char>(transitionGraph.size(),false);
    dfs_e(0);
    sort(epsilon.begin(), epsilon.end());
    states.push_back(epsilon);
    e[epsilon] = nodes++;

    for(int n=0; n<nodes; n++) {
        dfs(states[n], 1);
        sort(epsilon.begin(),epsilon.end());
        if(epsilon.size() > 0) {
            if(!e.count(epsilon)) {
                e[epsilon] = nodes++;
                states.push_back(epsilon);
                DFA.push_back({-1,-1});
            }
            DFA[n].first = e[epsilon];
        }

        dfs(states[n], 2);
        sort(epsilon.begin(), epsilon.end());
        if(epsilon.size()>0) {
            if(!e.count(epsilon)) {
                e[epsilon] = nodes++;
                states.push_back(epsilon);
                DFA.push_back({-1,-1});
            }
            DFA[n].second = e[epsilon];
        }
    }

    matrix = vector<vector<int>>(nodes,vector<int>(nodes));
    for(int n=0; n<nodes; n++) {
        if(DFA[n].first != -1) matrix[n][DFA[n].first]++;
        if(DFA[n].second != -1) matrix[n][DFA[n].second]++;
    }

    finalstate = vector<int>();
    for(int n=0; n<nodes; n++) {
        if(find(states[n].begin(), states[n].end(), 1) != states[n].end() )
            finalstate.push_back(n);
    }

}

void multMatrices(vector<vector<int>>& m1, vector<vector<int>>& m2) {
    vector<vector<int>> m3 (m1.size(), vector<int>(m1.size()));
    for(size_t x=0; x<m1.size(); x++) {
        for(size_t y=0; y<m1.size(); y++) {
            long long p = 0;
            for(size_t i=0; i<m1.size(); i++) {
                p = (p + m1[x][i] * 1LL * m2[i][y] ) % 1000000007;
            }
            m3[x][y] = (int)p;
        }
    }
    swap(m1, m3);
}

void matrixExponential(vector<vector<int>>& m, int k) {
    vector<vector<int>> m2 (m.size(), vector<int>(m.size()) );
    for(size_t i=0; i<m.size(); i++) 
        m2[i][i]=1;

    while(k>0) {
        if(k & 1) multMatrices(m2, m);
        k >>= 1;
        if(k > 0) multMatrices(m, m);
    }
    swap(m2, m);
}

long long countStrings(string r, int l) {
    transitionGraph.clear();
    transitionGraph.push_back(vector<pair<int,int>>());
    transitionGraph.push_back(vector<pair<int,int>>());

    int index = 0;
    buildNFA(r,index,0,1);

    convertToDFA();

    for(auto a : DFA) cout << a.first << " " << a.second << endl;

    matrixExponential(matrix, l);

    long long result = 0;
    for(auto f : finalstate)
        result += matrix[0][f];

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string rl_temp;
        getline(cin, rl_temp);

        vector<string> rl = split_string(rl_temp);

        string r = rl[0];

        int l = stoi(rl[1]);

        long long result = countStrings(r, l);

        fout << result % 1000000007  << "\n";
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
