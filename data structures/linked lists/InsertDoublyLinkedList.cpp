

// Complete the sortedInsert function below.

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
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* n = new DoublyLinkedListNode(data);
    DoublyLinkedListNode* res = head;
    if(head->data > data) {
        n->prev = NULL; 
        n->next = head;
        head->prev = n;        
        return n;
    }
    else {
        while(head->data <= data) {
            if(head->next == NULL) break;
            if(head->next->data >= data) break;
            head = head->next; 
        }
        n->prev = head;
        n->next = head->next;
        if(head->next!=NULL) head->next->prev = n;
        head->next = n;
    }
    return res;
}

