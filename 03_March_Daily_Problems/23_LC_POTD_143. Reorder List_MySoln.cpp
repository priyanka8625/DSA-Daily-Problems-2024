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
    void reorderList(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* temp = head;
        while(temp){
            nodes.push(temp);
            temp = temp->next;
        }
        solve(head, nodes);
    }
    void solve(ListNode* &Li, stack<ListNode*> &nodes){
        ListNode* lastNode=NULL, *prevNode=NULL;
        if(!nodes.empty()){
            lastNode = nodes.top();
            nodes.pop();
            if(!nodes.empty())
                prevNode = nodes.top();
        }
        if(Li == lastNode || Li->next == lastNode){
            return;
        }

        //otherwise update the links
        if(prevNode != NULL)
            prevNode->next = NULL;//break the link between last and it's prev node
        //node pointer will be connected to last now 
        //and last's next will be the next of node
        lastNode->next = Li->next;
        Li->next = lastNode;

        //call the function for Li+1 i.e. jump next->next
        solve(Li->next->next, nodes);
    }
};