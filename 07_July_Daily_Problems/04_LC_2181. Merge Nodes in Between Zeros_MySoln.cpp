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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev=head->next, *curr=head->next;
        while(curr){
            int sum=0;
            while(curr && curr->val != 0){
                sum += curr->val;
                // ListNode* delNode = curr;
                curr = curr->next;
                // delete delNode;
            } 
            prev->val = sum;
            curr = curr->next;
            prev->next = curr;
            prev = curr;
        }
        return head->next;
    }
};