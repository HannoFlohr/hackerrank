

class LRUCache : public Cache {
public: 
    LRUCache(int c) { cp=c; }

    void insertNode(int k, int v) {
        Node * newNode = new Node(k,v);
        if(mp.size()==0) {
            head = newNode;
            tail = newNode;
            tail->prev = head;
            head->next = tail;
        }
        tail->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        head = newNode;
        mp.insert( pair<int,Node*>(k,newNode) );
    }

    void deleteNode(int k) {
        map<int,Node*>::iterator it;
        it = mp.find(k);
        Node& del = *it->second;

        del.prev->next = del.next;
        del.next->prev = del.prev;

        //the tail element gets removed, therefore set tail to prev Node
        tail = del.prev;

        //remove element from mp and delete the Node
        mp.erase(k);
        delete &del;
    }

    void set(int k, int v) {
        if(mp.size() == 0) {
            insertNode(k,v);        
            return;        
        }

        //cout << "check if in cache.."<<endl;

        //check if key is in cache
        map<int,Node*>::iterator it;
        it = mp.find(k);
        //key is in cache -> set new value and update to head of cache
        if(it != mp.end() ) {
            //cout << "found, updating.." << endl;
            Node& node = *it->second;
            node.value = v;
            node.prev->next = node.next;
            node.next->prev = node.prev;
            node.next = head;
            node.prev = tail;
            tail->next = &node;
            head->prev = &node;
            head = &node;
            //cout << "updated" << endl;
        }
        else { //key is not in cache
            //if cache is full, delete tail Node 
            if(mp.size() == cp) deleteNode(tail->key);
            //insert new Node
            insertNode(k,v);
        }
    }

    /*void settest(int k, int v) {
        setNew(k,v);
        cout << "map size: " << mp.size() << endl;
    }*/

    int get(int k) {
        /*for(auto m : mp) {
            Node *n = m.second;
            cout << n->key << " " << n->value << endl;
        }*/

        map<int,Node*>::iterator it;
        it = mp.find(k);
        if(it != mp.end() ) {
            return it->second->value;
        }
        else return -1;
    }
};

