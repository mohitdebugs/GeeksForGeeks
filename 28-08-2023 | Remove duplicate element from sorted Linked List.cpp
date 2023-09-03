Node *removeDuplicates(Node *head)
{
    Node *temp = head;
    while(temp->next != NULL){
        while(temp->data == temp->next->data){
            temp->next = temp->next->next;
            if(temp->next == NULL){
                return head;
            }
        }
        temp = temp->next;
    }
    return head;
}
