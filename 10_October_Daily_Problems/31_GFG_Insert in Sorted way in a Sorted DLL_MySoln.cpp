class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        // Code here
        Node *curr=head, *tail=NULL;
        Node *newNode = new Node();
        newNode->data = x;
        newNode->prev = newNode->next = NULL;
        
        while(curr && curr->data < x){
            tail = curr;
            curr = curr->next;
        }
        if(curr == head){
            //insert at begin
            newNode->next = curr;
            curr->prev = newNode;
            head = newNode;
        }else if(curr == NULL){
            //insert at end
            tail->next = newNode;
            newNode->prev = tail;
        }else{
            curr->prev->next = newNode;
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev = newNode;
        }
        return head;
    }
};