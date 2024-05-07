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
    ListNode* doubleIt(ListNode* head) {
        //O(n) soln -> 1.reverse the list 2. get the sum 3. reverse the sum
        //reverse the list
        ListNode* prev=NULL, *curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //now perform addition
        head = prev;//now head is updated, pointing to the head of reversed list
        curr = prev, prev=NULL;
        int sum=0, carry=0;
        while(curr){
            //take the sum as node->val + val + carry
            sum = curr->val + curr->val + carry;
            carry = sum/10;
            sum = sum%10;
            //put sum into curr->val
            curr->val = sum;
            prev = curr;
            curr = curr->next;
        }
        //now curr is NULL and prev points to the last node
        //check if the carry is available 
        while(carry){
            sum = carry%10;
            carry = carry/10;
            ListNode* newNode = new ListNode(sum);
            prev->next = newNode;
            prev = prev->next;
        }
        //reverse the sum 
        prev = NULL, curr = head;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};