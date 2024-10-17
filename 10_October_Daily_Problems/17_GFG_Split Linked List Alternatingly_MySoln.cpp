class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node* even=NULL, *odd=NULL, *temp=head;
        int index=0;
        
        Node* e_tail = even, *o_tail=odd;
        while(temp){
            if(index%2 == 0){
                if(!even){
                    even = temp;
                    e_tail = even;
                }else{
                    e_tail->next = temp;
                    e_tail = e_tail->next;
                }
            }else{
                if(!odd){
                    odd = temp;
                    o_tail = odd;
                }else{
                    o_tail->next = temp;
                    o_tail = o_tail->next;
                }
            }
            index++;
            temp = temp->next;
        }
        
        if(e_tail)
            e_tail->next = NULL;
        if(o_tail)
            o_tail->next = NULL;
        
        
        return {even, odd};
    }
};
