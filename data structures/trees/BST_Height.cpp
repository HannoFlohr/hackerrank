
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root->left==NULL && root->right==NULL) return 0;

        int max_child;
        if(root->left==NULL && root->right!=NULL) 
            return height(root->right) + 1;
        else if(root->left!=NULL && root->right==NULL)
            return height(root->left) + 1;
        else 
            return max( (height(root->right) + 1), height(root->left) + 1 );
    }

