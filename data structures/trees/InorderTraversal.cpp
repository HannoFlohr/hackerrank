

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

    void out(Node* n) {
        std::cout << n->data << " ";
    }

    void inOrder(Node *root) {
        if(root==NULL) return;

        if(root->left == NULL && root->right == NULL) 
            out(root);
        else {
            inOrder(root->left);
            out(root); 
            inOrder(root->right);
        }
    }

