/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    
	bool checkBST(Node* root) {
		static int last_visited = -2;
        if(root==NULL) return true;

        if(!checkBST(root->left)) return false;
        if(root->data <= last_visited) return false;
        
        last_visited = root->data;
        if(!checkBST(root->right)) return false;
        
        return true;
	}