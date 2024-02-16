/* Node of the binary search tree 
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        // code here
        Node* list=NULL, *curr=NULL;
        sortBST(root, list, curr);
        return list;
    }
    void sortBST(Node* node, Node* &list, Node* &curr){
        //if we reach any left or right pointer which is null
        if(node == NULL)
            return;
            
        if(node->left == NULL && node->right == NULL){
            //insert this leaf node into list
            Node* temp = new Node(node->data);
            if(list == NULL){
                list = temp;
                curr = temp;
                return;
            }
            //if not first time insertion
            curr->right = temp;
            curr = temp;//update curr leaf node of new list
            return;
        }
        
        
        
        //traverse left subtree
        sortBST(node->left, list, curr);
        
        //insert the current root of subtree into list
        Node* temp = new Node(node->data);
        if(list == NULL){
            list = temp;
            curr = temp;
        }else{
            //if not first time insertion
            curr->right = temp;
            curr = temp;//update curr leaf node of new list
        }
        
        //traverse right subtree
        sortBST(node->right, list, curr);
    }
};