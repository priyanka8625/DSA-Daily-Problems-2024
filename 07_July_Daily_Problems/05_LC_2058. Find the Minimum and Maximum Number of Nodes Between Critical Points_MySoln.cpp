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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return {-1, -1};
            
        vector<int> positions;
        //find critical nodes
        ListNode* prev=head, *curr=head->next, *nxt=head->next->next;
        int position=1;
        while(nxt){
            position++;
            if(curr->val>prev->val && curr->val>nxt->val){
                positions.push_back(position);
            }else if(curr->val<prev->val && curr->val<nxt->val){
                positions.push_back(position);
            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        if(positions.size()<=1)
            return {-1, -1};

        //get min and max distance
        int minDistance=INT_MAX, maxDistance=INT_MIN;
        for(int i=1; i<positions.size(); i++){
            minDistance = min(minDistance, positions[i]-positions[i-1]);
        }
        maxDistance = positions[positions.size()-1]-positions[0];
        return {minDistance, maxDistance};
    }
};