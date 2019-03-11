

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode * n = head;
    SinglyLinkedListNode * newNode = new SinglyLinkedListNode(data);
    
    if(position==0) {
        newNode->next = head;
        return newNode; 
    }
    
    for(int i=0; i<position-1; i++) {
        if(head->next != NULL) n = n->next; 
    }
    newNode->next = n->next;
    n->next = newNode;
    return head;
}

