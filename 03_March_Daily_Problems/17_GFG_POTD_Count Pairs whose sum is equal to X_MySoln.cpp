/*Structure of the node of the linked list is as
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
class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        unordered_set<int> eles;
        int count=0;
        Node *temp = head1;
        while(temp!= NULL){
            eles.insert(temp->data);
            temp = temp->next;
        }
        //now traverse head2
        temp = head2;
        while(temp != NULL){
            int diff = x-temp->data;
            if(eles.find(diff) != eles.end())
                count++;
            temp = temp->next;
        }
        return count;
    }
};