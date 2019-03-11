

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	if(head==nullptr) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        head = newNode;
        return head;
    }
    
    SinglyLinkedListNode * node = head;
    while(node->next != nullptr) { 
        node = node->next;
    }
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    node->next = newNode;
    
    return head;
}

