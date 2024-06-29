class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1){
            //delete head of the list
            Node* delNode = head;
            head = head->next;
            head->prev = NULL;
            delete delNode;
            return head;
        }
        Node* delNode = head;
        while(x!=1){
            x--;
            delNode = delNode->next;
        }
        //remove connection links of prev and next of delNode
        delNode->prev->next = delNode->next;
        if(delNode->next != NULL)
            delNode->next->prev = delNode->prev;
        delete delNode;
        return head;
    }
};
