class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node* prev=NULL, *curr=head, *nxt=head->next;
        while(curr){
            nxt = curr->next;
            bool flag = false;
            while(nxt && curr->data == nxt->data){
                Node* delNode = nxt;
                nxt = nxt->next;
                delete delNode;
                flag = true;
            }
            if(flag){
                //means curr is the duplicate ele and nxt is poiting to next unique ele of curr
                if(prev){
                    prev->next = nxt;
                }else{
                    head = nxt;
                }
                delete curr;
            }else{
                prev = curr;
            }
            curr=nxt;
        }
        return head;
    }
};