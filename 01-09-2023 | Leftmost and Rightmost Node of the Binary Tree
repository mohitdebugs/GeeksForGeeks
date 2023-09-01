void printCorner(Node *root)
{
     queue<Node *>qu;
      qu.push(root);

      int size;
      Node * temp;
      int k;
      while(!qu.empty())
      {
          size=qu.size();
          k=0;
          while(k<size)
          {
             temp=qu.front();

             if(k==0)
             cout<<temp->data<<" ";
             else if(k==size-1)
             cout<<temp->data<<" ";

             k+=1;

             if(temp->left!=NULL)
             qu.push(temp->left);
             if(temp->right!=NULL)
             qu.push(temp->right);

             qu.pop();
          }
}
}
