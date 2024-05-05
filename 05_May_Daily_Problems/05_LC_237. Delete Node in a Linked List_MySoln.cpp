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
    void deleteNode(ListNode* node) {
        //we need to delete only the current node 
        //we can simply copy the data of next node into the give node 
        //and make the given node point to the node->next->next 
        //by doing this the current node will be a copy of it's next and it will point to the rest of the list as it is
        node->val = node->next->val;
        node->next = node->next->next;
    }
};