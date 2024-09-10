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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head, *next=head->next;
        while(curr && next){
            int divisor = __gcd(curr->val, next->val);
            ListNode *gcdNode = new ListNode(divisor);
            curr->next = gcdNode;
            gcdNode->next = next;
            curr = next;
            next = curr->next;
        }
        return head;
    }
};