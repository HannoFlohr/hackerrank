#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class Node {
public: 
    int id;
    vector<Node*> c;
    int weight;
    Node(int i) {
        id=i;
        weight=0;
        c = vector<Node*>();
    }
};

void setWeight(Node* n, vector<bool>& visited) { 
    visited[n->id] = true;
    if(n->c.empty()) {
        n->weight = 1;
        return;
    }

    int weight = 1;
    for(int i=0; i<n->c.size(); i++) {
        if(visited[n->c[i]->id] == true) continue;
        setWeight( n->c[i], visited );
        weight += n->c[i]->weight;
    }
    n->weight = weight;
}

// Complete the evenForest function below.
int evenForest(int n, int e, vector<int> t_from, vector<int> t_to) {
    vector<Node*> nodes;
    for(int i=0; i<n; i++) 
        nodes.push_back(new Node(i));
    for(int i=0; i<e; i++) {
        nodes[ t_from[i]-1 ]->c.push_back( nodes[ t_to[i]-1 ] );
        nodes[ t_to[i]-1 ]->c.push_back( nodes[ t_from[i]-1 ] );
    }

    Node* root = nodes[0];
    vector<bool> visited(n,false);
    setWeight(root,visited);

    int cuts=0;
    for(int i=1; i<n; i++)
        if(nodes[i]->weight % 2 == 0) cuts++;

    return cuts;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
