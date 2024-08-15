
class Solution {
  public:
    
    Node *reverse(Node *root){
        if(root==NULL || root->next==NULL)return root;
        
        Node *New=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        
        return New;
    }
    
    Node* addOne(Node* head) {
        head=reverse(head);
        Node *curr=head;
        Node *prev=NULL;
        int carry=1;
        
        while(curr!=NULL && carry)
        {
            int newNum=curr->data+carry;
            curr->data=newNum%10;
            carry=newNum/10;
            prev=curr;
            curr=curr->next;
        }
        
        if(carry)
        {
            prev->next=new Node(carry);
        }
        
        return reverse(head);
    }
};