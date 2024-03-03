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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        //the node to be deleted will be 5-2+1'th node for n=2, size=5, delete=4
        int toDelete = size-n+1;

        if(toDelete == 1){
            //we need to delete the first element hence head will be changed here
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int count=2;
        ListNode* prev = head;
        temp = head->next;
        while(temp != NULL){
            if(count == toDelete){
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = prev->next;
            temp = temp->next;
            count++;
        }
        return head;
    }
};