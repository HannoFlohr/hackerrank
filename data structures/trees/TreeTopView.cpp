

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
    typedef pair<int,int> headview;
    map<int,headview> view;
    map<int,headview>::iterator it; 

    void makeTopView(Node* root, int i, int h) {
        if(root==NULL) return; 

        it = view.find(i);
        if(it==view.end())
            view[i] = make_pair(h,root->data);
        else {
            if(it->second.first > h)
                view[i] = make_pair(h,root->data);
        }
        if(root->left!=NULL)
            makeTopView(root->left,i-1,h+1);
        if(root->right!=NULL)
            makeTopView(root->right,i+1,h+1);
    }

    void printTopView() {
        for(it=view.begin(); it!=view.end(); ++it)
            cout << it->second.second<<" ";
    }

    void topView(Node * root) {
        makeTopView(root,0,0);
        printTopView();
        return; 
    }

