class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        Node* odd=head, *even=head->next;
        while(even){
            odd->next = even->next;
            odd = odd->next;
            if(even->next)
                even = even->next->next;
            else
                even = NULL;
        }
    }
};