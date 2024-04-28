/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
        if(head==NULL || head->next==NULL)
            return NULL;
            
        //let's apply two pointers -> fast and slow 
        Node* slow = head, *fast = head, *prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //now slow will ponint the node to be deleted in the middle
        prev->next = slow->next;
        // delete slow;
        return head;
    }
};