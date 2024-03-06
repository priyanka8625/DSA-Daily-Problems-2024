/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // we can use the two pointer technique here i.e. fast and slow pointers
        // slow pointer moves by 1 step whereas fast will move by 2 steps everytime 
        // if the linked list contains a cycle, then there will always be a condn 
        // where fast and slow pointers point to the same node
        // otherwise, while moving the fast pointer check if fast->next != null to avoid memory ref error

        //edge case 1- 0 nodes present
        if(head == NULL)
            return false;
        //edge case2 - one node present
        if(head->next == NULL)
            return false;//only one node is there

        //code for 2 or more nodes
        ListNode *slow=head, *fast=head->next->next;
        while(fast){
            if(slow == fast)
                return true;

            if(fast->next == NULL)
                return false;//there's no loop present, this will hold true only when ll doesn't have a loop
            
            fast = fast->next->next; 
            slow = slow->next;
        }
        return false;//no loop present
    }
};