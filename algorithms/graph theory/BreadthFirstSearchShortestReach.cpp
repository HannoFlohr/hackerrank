#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Node {
public:
    int id;
    int depth;
    vector<Node*> children;
    Node(int id) {
        this->id = id;
        depth = -1;
        children = vector<Node*>();
    }
};

void setDepth(Node* root, vector<bool>& visited) {
    queue<Node*> q;
    q.push(root);
    Node* node;
    while(!q.empty()) { 
        node = q.front(); 
        q.pop();
        
        if(!visited[node->id]) {
            visited[node->id] = true;
            for(int i=0; i<node->children.size(); i++) {
                if(!visited[ node->children[i]->id ]) {
                    if(node->children[i]->depth == -1)
                        node->children[i]->depth = node->depth + 1;
                    q.push(node->children[i]);
                }
            }
        }
    }
}

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    s--;
    vector<int> results;
    vector<Node*> nodes;
    for(int i=0; i<n; i++) nodes.push_back(new Node(i));
    Node* root = nodes[s];
    root->depth = 0;

    for(int i=0; i<m; i++) {
        nodes[ edges[i][0]-1 ]->children.push_back( nodes[ edges[i][1]-1 ] );
        nodes[ edges[i][1]-1 ]->children.push_back( nodes[ edges[i][0]-1 ] );
    }
    for(auto a:nodes) {
        sort(a->children.begin(),a->children.end());
        a->children.erase( unique( a->children.begin(), a->children.end() ), a->children.end() );
    }
    
    vector<bool> visited (n,false);
    setDepth(root,visited);

    int result;
    for(int i=0; i<n; i++) {
        if(i==s) continue;
        result = nodes[i]->depth;
        if(result != -1) result *= 6; 
        results.push_back( result );
    }

    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
