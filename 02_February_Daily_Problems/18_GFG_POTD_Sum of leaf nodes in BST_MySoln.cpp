
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
}; */


class Solution
{
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
             return sumOfLeaves(root, 0);
        }
        int sumOfLeaves(Node* node, int sum){
            if(node == NULL)
                return sum+0;
            if(node->left == NULL && node->right == NULL)
                return sum + node->data;
            
            //traverse left subtree and right subtree
            return sumOfLeaves(node->left, sum) + sumOfLeaves(node->right, sum);
        }
};