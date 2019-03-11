

// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode* n;
    if(position==0) {
        n = head->next;
        delete head;
        return n;
    }
    n = head;
    for(int i=0; i<position-1; i++) {
        n = n->next;
    }
    SinglyLinkedListNode* last = n; 
    n = n->next;
    last->next = n->next;

    delete n;
    return head;
}

