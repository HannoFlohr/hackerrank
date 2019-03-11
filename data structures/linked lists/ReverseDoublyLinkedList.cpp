

// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    vector<DoublyLinkedListNode*> v;
    v.push_back(head);
    while(head->next != NULL) {
        head = head->next;
        v.push_back(head);
    }
    reverse(v.begin(),v.end());

    for(int i=0; i<v.size(); i++) {
        if(i==0) v[i]->prev = NULL;
        else v[i]->prev = v[i-1];
        if(i==v.size()-1) v[i]->next = NULL ;
        else v[i]->next = v[i+1];
    }
    return v[0];
}

