#include<bits/stdc++.h>
using namespace std;

/* 
At first tried to create a directed graph and use the indegrees to construct the password (20/22 tests passed, see below). 
Than realized that it could be done simpler: 
(1) create a mapping for chars->previous chars
(2) to recreate the password
- find the lexicographically smallest char with no predecessors (= node with indegree=0)
- add that char to the password and remove it from the mapping
- repeat till map is empty
*/
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    //generate the mappings to previous characters from logins
    map<char, set<char>> prev;
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        prev[s[0]];
        prev[s[1]].insert(s[0]);
        prev[s[2]].insert(s[1]);
    }
    
    //reconstruct the password
    string password = "";
    while(!prev.empty()) {
        auto next_char_pos = prev.begin();
        while(next_char_pos != prev.end() && !next_char_pos->second.empty())
            next_char_pos++;
            
        if(next_char_pos==prev.end()) {
            password = "SMTH WRONG";
            break;
        }
        
        password += next_char_pos->first;
        
        prev.erase(next_char_pos->first);
        for(auto &p:prev)
            p.second.erase(next_char_pos->first);
    }
    
    cout << password << endl;
    return 0;
}
//https://www.hackerrank.com/contests/projecteuler/challenges/euler079/problem

/*
#include<bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    vector<char> next = vector<char>();
    vector<Node*> prev = vector<Node*>();
    unsigned int indegree;
}; 

vector<Node*> nodes;
map<unsigned int,vector<Node*>> indegrees;

bool hasNode(char c) {
    for(auto n:nodes)
        if(n->c == c)
            return true; 
    return false;
}

Node* getNode(char c) {
    for(auto n:nodes)
        if(n->c == c)
            return n;
    return NULL;
}

void removeNode(Node* n) {
    //reduce the indegree of the nodes following this one
    for(auto c:n->next) {
        unsigned int pos=0;
        while(nodes[pos]->c != c)
            pos++;
        nodes[pos]->indegree--; 
    }
    
    //remove the node from the nodes vector
    unsigned int pos=0;
    while(nodes[pos]->c != n->c)
        pos++;
    nodes.erase(nodes.begin()+pos);
}

void updateIndegrees() {
    indegrees.clear();
    for(auto n:nodes) 
        indegrees[n->indegree].push_back(n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    
    //intialize all nodes
    while(t--) {
        string s;
        cin >> s;
        for(int i=0; i<3; i++) {
            //if new node, add it
            if(!hasNode(s[i])) {
                Node* n = new Node();
                n->c = s[i];
                
                if(i==0) 
                    n->next.push_back(s[1]);
                else if(i==1) {
                    n->prev.push_back(getNode(s[0]));
                    n->next.push_back(s[2]);
                }    
                else 
                    n->prev.push_back(getNode(s[1]));
                
                
                nodes.push_back(n);
            }
            else {
                Node* n = getNode(s[i]);
                if(i==0) 
                    n->next.push_back(s[1]);
                else if(i==1) {
                    n->prev.push_back(getNode(s[0]));
                    n->next.push_back(s[2]);
                }
                else 
                    n->prev.push_back(getNode(s[1]));
            }
        }   
    }
    
    //sort nodes by their char
    sort(nodes.begin(), nodes.end(), 
            [](const Node* n1, const Node* n2)->bool{
                return n1->c < n2->c;
            });
            
    //set indegrees of nodes
    for(auto n:nodes)
        n->indegree = n->prev.size();
    updateIndegrees();

    //reconstruct the password
    string password = "";
    //no starting point -> no solution
    if(indegrees[0].size() == 0 ){
        cout << "SMTH WRONG" << endl;
        return 0;
    } 
    while(!nodes.empty()) {
        Node* n = indegrees[0].front();
        password += n->c;
        removeNode(n);
        updateIndegrees();
        delete n;
    }
    
    cout << password << endl;
    return 0;
}
*/