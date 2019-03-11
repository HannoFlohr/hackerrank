

// Complete the getNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int getNode(SinglyLinkedListNode* head, int& positionFromTail) {
    int x;
    if(head->next!=NULL) x = getNode(head->next, positionFromTail);

    if(positionFromTail==0){positionFromTail--; return head->data; }
    else if(positionFromTail>0) { return positionFromTail--; }
    else return x;
}

