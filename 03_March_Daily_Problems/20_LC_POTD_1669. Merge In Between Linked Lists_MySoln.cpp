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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int index=0;
        ListNode* temp1 = list1, *prev=NULL;
        while(temp1 != NULL){
            if(index == a){
                //loop untill index b and remove the elements
                while(index != b+1){
                    prev->next = temp1->next;
                    ListNode* del = temp1;
                    temp1 = temp1->next; 
                    delete del;
                    index++;
                }
                break;
            }
            prev = temp1;
            temp1 = temp1->next;
            index++;
        }
        //after above while loop w'll have prev = a and prev->next = b
        temp1 = list2;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        //now prev->next should hold list2 and temp1->next should hold prev->next
        temp1->next = prev->next;
        prev->next = list2;
        return list1;
    }
};