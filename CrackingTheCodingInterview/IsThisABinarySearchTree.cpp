/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    
    vector<int> tree;

    void inOrderTraversal(Node* root) {
        if(root!=NULL) {
            inOrderTraversal(root->left);
            tree.push_back(root->data);
            inOrderTraversal(root->right);
        }
    }

	bool checkBST(Node* root) { 
		inOrderTraversal(root);
        
        for(int i=0; i<tree.size()-1; i++) 
            if(tree[i]>=tree[i+1]) 
                return false;
       
        return true;
	}