
/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root, string s) {
    int c, i=0;
    node * n = root;
    string result="";
    while(i<s.size()) {
        c = s[i]-'0';

        if(c==0) 
            n = n->left;
        else 
            n = n->right;
        
        if(n->data != NULL) {
            result += n->data;
            n = root;
        }

        i++;
    }

    cout << result << endl;
}

