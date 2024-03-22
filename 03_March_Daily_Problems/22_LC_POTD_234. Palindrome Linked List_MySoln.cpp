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
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        //left will point to the first element of first half and right to the first ele of second half
        ListNode *left = head, *right=head;
        int size=0;
        while(left){
            size++;
            left = left->next;
        }
        int toDelete = size/2;
        while(toDelete--){
            right = right->next;
        }
        left = head;
        return check(left, right);
    }
    bool check(ListNode* &left, ListNode* right){
        if(right == NULL)
            return true;
        
        //go forward untill right points to the last node
        bool flag = check(left, right->next);
        if(flag){
            //if previous comparison was true then sompare current values
            if(left->val == right->val)
                flag = true;
            else
                flag = false;
        }
        //and return flag after moving left forward for next comparison
        left = left->next;
        return flag;
    }
};