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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> to_delete(nums.begin(), nums.end());
        ListNode *curr=head, *prev=NULL;
        prev = new ListNode(0);
        head = prev;
        while(curr){
            if(to_delete.find(curr->val) == to_delete.end()){
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        if(prev)
            prev->next = NULL;
        return head->next;
    }
};