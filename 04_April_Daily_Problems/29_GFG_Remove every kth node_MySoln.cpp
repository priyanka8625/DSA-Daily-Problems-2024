/* Link list Node 

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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
    public:
    Node* deleteK(Node *head,int K){
      //Your code here
        if(K == 1)
        return NULL;
        
        Node* temp=head, *prev=NULL;
        int key=1;
        while(temp){
            if(key == K){
                //delete current node 
                prev->next = temp->next;
                Node *delNode = temp;
                temp = temp->next;
                delete delNode;
                //make Key = 1, for next iteration 
                key = 1;
            }else{
                //simply move to the next node
                prev = temp;
                temp = temp->next;
                key++;
            }
        }
        return head;
    }
};