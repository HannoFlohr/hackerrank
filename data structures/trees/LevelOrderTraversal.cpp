
/*
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
    map<int,vector<int>> levelOrderMap;

    void makeLevelOrder(Node* root, int i) {
        if(root==NULL);

        levelOrderMap[i].push_back(root->data);
        if(root->left!=NULL) makeLevelOrder(root->left,i+1);
        if(root->right!=NULL) makeLevelOrder(root->right,i+1);
    }

    void printLevelOrder() {
        for(map<int,vector<int>>::iterator it=levelOrderMap.begin(); it!=levelOrderMap.end(); ++it) {
            vector<int> v = (*it).second;
            for(auto a:v) cout << a << " ";
        }
    }

    void levelOrder(Node * root) {
        if(root==NULL) return;
        makeLevelOrder(root,0);
        printLevelOrder();
        return;
    }

