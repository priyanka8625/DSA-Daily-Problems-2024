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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = getSize(head);
        int subpartSize = n/k;
        int extra = n%k;
        ListNode* curr = head, *subpartHead=head;
        vector<ListNode*> ans(k, NULL);

        for(int i=0; i<k && curr; i++){
            subpartHead = curr;
            int j=1;
            while(j<subpartSize && curr){
                curr = curr->next;
                j++;
            }
            //include an extra node in the first extra parts
            if(i < extra && j<=subpartSize){
                curr = curr->next;
            }
            if(curr){
                ListNode* next = curr->next;
                curr->next = NULL;
                curr = next;
            }
            ans[i] = subpartHead;
        }
        return ans;
    }
    int getSize(ListNode* head){
        if(!head)
            return 0;
        int count=0;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
};