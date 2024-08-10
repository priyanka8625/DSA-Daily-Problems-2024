class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) {
        // Your code here
        Node *curr=head, *prev=NULL;
        int index=1;
        while(curr && index<=k){
            prev = curr;
            curr = curr->next;
            index++;
        }
        //now curr points to k+1'th node and prev is k'th node
        if(curr){
            if(prev)
                prev->next = NULL;
            //go to the last node and append the nodes from head->prev over there
            Node* oldHead = head;
            head = curr;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = oldHead;
        }
        return head;
    }
};