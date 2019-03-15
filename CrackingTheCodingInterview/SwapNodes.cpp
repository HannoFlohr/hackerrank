#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int id;
    Node* parent;
    Node* left;
    Node* right;
    int depth;
    Node(int d) {id=d; depth=-1; parent=NULL; left=NULL; right=NULL; }
    Node(int d, int de) {id=d; depth=de; parent=NULL; left=NULL; right=NULL; }

    void out(){
        cout << id << " ";
        left==NULL ? cout<<-1<<" " : cout<<left->id<<" ";
        right==NULL ? cout<<-1<<" " : cout<<right->id<<" ";
        cout << depth <<endl;
    }
}; 

vector<Node*> nodelist;
int maxDepth = -1;

void setDepth() {
    Node* n;
    nodelist[1]->depth = 0;
    for(int i=1; i<nodelist.size(); i++) {
        n = nodelist[i];
        if(n->left != NULL) n->left->depth = n->depth + 1;
        if(n->right != NULL) n->right->depth = n->depth + 1;
    }

    for(int i=nodelist.size()-1; i>=1; i--) 
        maxDepth = max(maxDepth,nodelist[i]->depth);
}

void inOrder(Node* root) {
    if(root==NULL) return;

    if(root->left != NULL) inOrder(root->left);
    std::cout << root->id << " "; 
    if(root->right != NULL) inOrder(root->right);
}

void swapNodes(int k) {
    Node* node; 
    Node* temp;
    int depth = k;
    while(depth<=maxDepth) {
        int parentDepth = depth-1;
        for(int i=1; i<nodelist.size(); i++) {
            node = nodelist[i];
            if(node->depth == parentDepth) {
                temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }
   
        depth += k;
    }
}

int main()
{
    int n,q,left,right,k;
    cin >> n;
    Node* node;
    for(int i=0; i<=n; i++) {
        node = new Node(i);
        nodelist.push_back(node);
    }
    Node* root = nodelist[1];
    
    for (int i=1; i<=n; i++) {
        cin >> left >> right;
        node = nodelist[i];
        if(left != -1) {
            node->left = nodelist[left];
            nodelist[left]->parent = node;
        }
        if(right != -1) {
            node->right = nodelist[right];
            nodelist[right]->parent = node;
        }
    }
    setDepth();

    cin >> q;
    while(q--) {
        cin >> k;
        swapNodes(k);
        inOrder(root);
        cout<<endl;
    }

    return 0;
}
