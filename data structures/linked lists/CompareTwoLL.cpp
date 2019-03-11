

// Complete the compare_lists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while( head1->next != NULL ) {
        if(head1->data != head2->data) 
            return false;
        if(head2->next != NULL) 
            head2 = head2->next;
        else 
            return false;
        head1 = head1->next;
    }
    return true;
}

