

// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    vector<SinglyLinkedListNode*> v;
    v.push_back(head);
    while(head->next != NULL) {
        v.push_back(head->next);
        head = head->next;
    }

    reverse(v.begin(),v.end());

    for(int i=0; i<v.size()-1; i++) {
        v[i]->next = v[i+1];
    }
    v[v.size()-1]->next = NULL;

    return v[0];
}

