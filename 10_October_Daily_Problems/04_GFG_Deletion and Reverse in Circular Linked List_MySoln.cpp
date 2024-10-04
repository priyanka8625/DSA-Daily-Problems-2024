class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        Node *curr = head->next, *prev = head, *next=NULL;
        while(curr != head){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        if(head->data == key){
            Node *curr = head->next;
            while(curr->next != head){
                curr = curr->next;
            }
            curr->next = head->next;
            head = head->next;
            return head;
        }
        Node *curr=head, *prev=head;
        while(curr->next != head && curr->next->data != key){
            curr = curr->next;
        }
        if(curr->next->data == key)
            curr->next = curr->next->next;
        return head;
    }
};