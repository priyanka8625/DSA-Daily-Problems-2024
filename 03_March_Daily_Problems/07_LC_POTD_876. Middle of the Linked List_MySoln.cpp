/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        //let's slow fast pointer technique on the linked lists
        //if we observe the two cases of finding the middle vaues,
        //1. Odd no. of nodes: slow will point to middle value when fast->next is null
        //2. even no. of nodes: slow will point to middle value when fast is null
        //start both fast and slow from head

        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};