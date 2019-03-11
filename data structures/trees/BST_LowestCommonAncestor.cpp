

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
   
    Node* find(Node* root, vector<int> &ancestors, const int &v, bool &found) {
        //cout << "node " << root->data << endl;
        if(root->data == v) { //cout << "found " << v << endl;
            found = true;
            ancestors.push_back(v);
            return root;
        }

        //search left node
        if(root->left != NULL) {
        //cout << "search left" << endl;
        Node * n = find(root->left,ancestors,v,found);
        if(found) { //cout << "adding " << root->data << endl;
            ancestors.push_back(root->data);
            return n;
        }
        }

        //search right node
        if(root->right != NULL) {
        //cout << "search right" << endl;
        Node * n = find(root->right,ancestors,v,found);    
        if(found) { //cout << "adding " << root->data << endl; 
            ancestors.push_back(root->data);
            return n;
        }
        }

        //cout<<"RETURNING NULL" << endl;
        return NULL;
    }


    Node *lca(Node *root, int v1,int v2) {//cout << "rootdata: " << root->data << endl;
		// Write your code here.
        if(root->left==NULL && root->right==NULL) return NULL;

        vector<int> ancestors1;
        vector<int> ancestors2;
        bool found=false;
        Node * n1 = find(root,ancestors1,v1,found); 
        if(n1==NULL) {cout<<"error with n1"; exit(1);}
        found=false;
        Node * n2 = find(root,ancestors2,v2,found); 
        if(n2==NULL) {cout<<"error with n2"; exit(1);}

        reverse(ancestors1.begin(),ancestors1.end());
        reverse(ancestors2.begin(),ancestors2.end());

        //ancestors1.erase(unique(ancestors1.begin(),ancestors1.end()), ancestors1.end() );
        //ancestors2.erase(unique(ancestors2.begin(),ancestors2.end()), ancestors2.end() );
        /*for(auto a:ancestors1) cout << a << " ";
        cout << endl;
        for(auto a:ancestors2) cout << a << " ";
        cout << endl; */

        int i=ancestors1.size() -1;
        int j=ancestors2.size() -1;
        int lowest_ancestor = -1;
        
        vector<int> intersection;
        set_intersection(ancestors1.begin(),ancestors1.end(),
                            ancestors2.begin(),ancestors2.end(),
                            back_inserter(intersection));
        //intersection.erase(unique(intersection.begin(),intersection.end()), intersection.end() );
        
        /*cout<<"inter: ";
        for(auto a:intersection) cout << a << " ";
        cout << endl; */
        if(intersection.size()==1) 
            lowest_ancestor = intersection[0];
        else {
            lowest_ancestor = intersection[intersection.size()-1];
        }
        
        if(lowest_ancestor==-1) {cout<<"error with lca"<<endl; exit(1);}
        //cout << "lca: " << lowest_ancestor << endl;

        found = false;
        n1 = find(root,ancestors1,lowest_ancestor,found);
        if(n1==NULL) cout << "n1 NULL"<<endl;
        //cout << "data: " <<n1->data<< endl;

        return n1;
    }

