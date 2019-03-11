

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* newHead;
    if(head1->data <= head2->data) { 
        newHead = head1;
        head1 = head1->next;
    }
    else {
        newHead = head2;
        head2 = head2->next;
    } 
    SinglyLinkedListNode* nh = newHead;


    while(!(head1 == NULL && head2 == NULL)) {      
        if(head1 == NULL) {
            newHead->next = head2;
            head2 = head2->next;
            cout << "set2 ";}
        else if(head2 == NULL) {
            newHead->next = head1;
            head1 = head1->next;
            cout << "set1 ";
        }
        else if(head1->data <= head2->data) { 
            newHead->next = head1; 
            head1 = head1->next; 
        }
        else { 
            newHead->next = head2;
            head2 = head2->next;
        }
        newHead = newHead->next;
    }
    newHead->next = NULL; 
    return nh;
}

