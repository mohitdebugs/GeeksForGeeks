Node* deleteNode(Node *head,int x)
{
    if(head==NULL)
    {
        return head;
        exit(0);
    }
    Node *temp=head;
    Node *q=temp;
    if(x==1)
    {
        head=head->next;
    }
    for(int i=0;i<x-1;i++)
    {
        q=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        q->next=NULL;
    }
    else
    {
        q->next=temp->next;
    }
    return head;
}
