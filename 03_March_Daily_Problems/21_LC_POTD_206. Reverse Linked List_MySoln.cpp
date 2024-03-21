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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        rev(head, prev, head);
        return head;
    }
    void rev(ListNode* currnode, ListNode* prevnode, ListNode* &head){
        if(currnode == NULL)
            return;
        if(currnode->next == NULL)//last node
            head = currnode;

        rev(currnode->next, currnode, head);
        // make curr's next = prev
        currnode->next = prevnode;
    }
};