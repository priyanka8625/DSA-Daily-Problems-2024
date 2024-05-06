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
    ListNode* removeNodes(ListNode* head) {
        //another approach optimised -> O(n) O(1)
        //1. reverse the linked list so that we can easily compare the rightmost nodes 
        //to check the given condn
        ListNode* prev=NULL, *curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        //2. now check if the curr node has >= value than it's prev node, if yes move forward ow skip
        //prev points to the new head now
        ListNode* tempPrev = prev;
        curr = prev->next;//point to 2nd node
        while(curr){
            if(curr->val>=tempPrev->val){
                tempPrev->next = curr;
                //move pointers
                tempPrev = curr;
                curr = curr->next;
            }else{
                curr = curr->next;
            }
        }
        //prev contains the last node of the modified list, it might happen that prev ponts to an intermidiate node and it's next is not NULL 
        tempPrev->next = NULL;

        //3. reverse this modified list to get the final answer
        //prev still points to the head node
        curr = prev;
        prev = NULL;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    
};