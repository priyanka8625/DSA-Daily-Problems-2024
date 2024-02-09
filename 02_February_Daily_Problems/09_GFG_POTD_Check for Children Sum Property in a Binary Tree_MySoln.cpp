/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
        return checkSum(root);
    }
    int checkSum(Node* node){
        if(node == NULL)
            return 1;
            
        if(node->left == NULL && node->right == NULL)//if the current node is leaf node then it is accepted as it is, no need to sum up anything
            return 1;
        
        int leftN = (node->left==NULL)? 0:node->left->data;
        int rightN = (node->right == NULL)? 0:node->right->data;
        if(node->data == (leftN+rightN) ){
            //move to the left and right subtree
            return checkSum(node->left) && checkSum(node->right);
        }else{
            return 0;
        }
    }
};