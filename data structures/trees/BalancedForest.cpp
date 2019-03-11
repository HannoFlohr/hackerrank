#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class GraphNode {
public:
    int value;
    vector<int> neighbors;
    GraphNode(int v) {
        value = v;
    }
};

class TreeNode {
public:    
    int value;
    TreeNode* parent;
    vector<TreeNode*> children;
    int enter;
    int exit;
    long sum;
    TreeNode(int v, TreeNode* p) {
        value = v;
        parent = p;
    }

    void to_string() {
        cout << "value="<<value<< " enter="<<enter<<" exit="<<exit;
        cout << " children="<<children.size();
        cout << endl;
    }
};

vector<GraphNode*> graphnodes;
vector<TreeNode*> treenodes;

void setGraphNodes(const vector<int> &c, const vector<vector<int>> &edges) {
    GraphNode* n;
    for(int i=0; i<c.size(); i++) {
        n = new GraphNode(c[i]);
        graphnodes.push_back(n);
    }
    for(auto e : edges) {
        graphnodes[e[0]-1]->neighbors.push_back(e[1]-1);
        graphnodes[e[1]-1]->neighbors.push_back(e[0]-1);
    }
}

int rootIndexWithMinHeight() {
    bool visited [graphnodes.size()];

    queue<int> q;
    for(int i=0; i<graphnodes.size(); i++) {
        if(graphnodes[i]->neighbors.size() == 1) {
            visited[i] = true;
            q.push(i);
        }
    }

    int root_index = -1, head;
    while(!q.empty() ) {
        head = q.front();
        q.pop();
        root_index = head;
        for(auto neighbor : graphnodes[head]->neighbors) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return root_index;
}

TreeNode* createTree(const int& root_index, bool* visited, TreeNode* parent, int& time) {
    visited[root_index] = true; 

    TreeNode* node = new TreeNode(graphnodes[root_index]->value, parent);
    treenodes.push_back(node);
    time++;
    node->enter = time;

    //create all children
    for(auto neighbor : graphnodes[root_index]->neighbors) {
        if(!visited[neighbor]) {
            TreeNode* tn = createTree(neighbor, visited, node, time);
            node->children.push_back(tn);
        }

    }

    time++;
    node->exit = time;
    return node;
}

void cleanup() {
    for(auto n:graphnodes) delete n;
    graphnodes.clear();
    for(auto n:treenodes) delete n;
    treenodes.clear();
}

void addToValueSum(map<long,vector<int> >& valueSumMap, long& valueSum, const int& time) {
    valueSumMap[valueSum].push_back(time);
}

void computeValueSums(map<long,vector<int> >& valueSumEnter, 
                        map<long,vector<int> >& valueSumExit,
                        TreeNode* node) {
    
    node->sum = node->value;

    for(auto child : node->children) {
        computeValueSums(valueSumEnter, valueSumExit, child);
        node->sum += child->sum;
    }

    addToValueSum(valueSumEnter, node->sum, node->enter);
    addToValueSum(valueSumExit, node->sum, node->enter);
}

bool contains(const map<long,vector<int> >& valueSumEnter, 
                const map<long,vector<int> >& valueSumExit,
                TreeNode* node, const long& targetSum) {
    auto exitIt = valueSumExit.find(targetSum);
    if(exitIt!=valueSumExit.end() ) {
        vector<int> v = (*exitIt).second;
        auto it = lower_bound(v.begin(),v.end(),node->enter); 
        if(it!=v.end() ) return true;
    }

    auto enterIt = valueSumEnter.find(targetSum);
    if(enterIt!=valueSumEnter.end() ) {
        vector<int> v = (*enterIt).second;
        auto it = upper_bound(v.begin(),v.end(),node->exit);
        if(it!=v.end() ) return true;
    }  

    for(TreeNode* p = node->parent; p!=NULL; p=p->parent ) {
        if(p->sum - node->sum == targetSum) {
            return true;
        }
    }
    return false;
}

void cutTree(const long& rootTotal, const map<long,vector<int> >& valueSumEnter, 
                const map<long,vector<int> >& valueSumExit, TreeNode* node, long& result) {
    long cut_sum = node->sum;
    long remaining = rootTotal - cut_sum;
    if(cut_sum <= remaining) {
        if(cut_sum == remaining) 
            result = min(result,cut_sum);
        else {
            if(remaining%2 == 0) {
                if( (remaining/2) >= cut_sum &&
                        contains(valueSumEnter,valueSumExit,node,(remaining/2)) ) {
                    result = min(result, (remaining/2)-cut_sum );
                }
            }

            long other_sum = remaining - cut_sum;
            if(cut_sum >= other_sum &&
                (contains(valueSumEnter,valueSumExit,node,other_sum) || 
                contains(valueSumEnter,valueSumExit,node,(cut_sum-other_sum)) ) ) {
                    result = min(result, cut_sum-other_sum);
            }
        }

    }

    for(auto child : node->children) 
        cutTree(rootTotal, valueSumEnter, valueSumExit, child, result);
}

// Complete the balancedForest function below.
int balancedForest(vector<int> c, vector<vector<int>> edges) {
    if(edges.size() < 3 ) return -1;

    //fill the graphnodes vector
    setGraphNodes(c,edges);

    if(graphnodes.size() < 3) return -1;
    
    //compute the root index for the tree
    int root_index = rootIndexWithMinHeight();

    //create the tree
    int createTime = 0;
    bool visited [graphnodes.size()] = {false};
    TreeNode* root = createTree(root_index, visited, NULL, createTime);
    
    //setup the sum for all nodes for enter/exit
    map<long,vector<int> > valueSumEnter;
    map<long,vector<int> > valueSumExit;
    computeValueSums(valueSumEnter, valueSumExit, root);

    //cut the tree to look for potential solutions
    long required_value = numeric_limits<long>::max();
    cutTree(root->sum,valueSumEnter,valueSumExit, root, required_value);

    cleanup();
    return required_value == numeric_limits<long>::max() ? -1 : required_value;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string c_temp_temp;
        getline(cin, c_temp_temp);

        vector<string> c_temp = split_string(c_temp_temp);

        vector<int> c(n);

        for (int i = 0; i < n; i++) {
            int c_item = stoi(c_temp[i]);

            c[i] = c_item;
        }

        vector<vector<int>> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = balancedForest(c, edges);

        fout << result << "\n";
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
