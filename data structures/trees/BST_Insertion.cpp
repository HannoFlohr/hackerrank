

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void insertNode(Node* n, int data) {
        if(n==NULL) return;
        if(n->data > data) {
            if(n->left==NULL) 
                n->left = new Node(data);
            else
                insertNode(n->left,data);
        }
        else { // n->data < data
            if(n->right==NULL) 
                n->right = new Node(data);
            else
                insertNode(n->right,data);
        }
    }

    Node * insert(Node * root, int data) {
        if(root==NULL) {
            root = new Node(data);
            return root;
        }
        insertNode(root,data);
        return root;
    }

