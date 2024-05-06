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
        //we'll iterate the linked list in revrse order by manintaining a max variable from end till current node
        int max =  -1;
        return getNewLinkedList(head, max);
    }
    ListNode* getNewLinkedList(ListNode* node, int &max){
        if(node->next == NULL){
            max = node->val;
            return node;
        }
        //traverse the linked list till you reach the last node
        node->next = getNewLinkedList(node->next, max);
        //now compare the current node with max node at it's right
        //note that this recursion calls will make sure that the max value node is always in the next of current node
        if(max > node->val){
            //we need to delete this node
            return node->next;//return the max node 
        }
        //else update max node and return the current node as there's no node maximum than this at right
        max = node->val;
        return node;
    }
};