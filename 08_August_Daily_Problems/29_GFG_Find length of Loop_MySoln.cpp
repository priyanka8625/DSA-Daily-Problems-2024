class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        int count=1;
        Node* slow = head, *fast = head;
        //check if cycle is there
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                Node *curr = slow->next;
                while(curr != slow){
                    count++;
                    curr = curr->next;
                }
                return count;
            }
        }
        return 0;
    }
};