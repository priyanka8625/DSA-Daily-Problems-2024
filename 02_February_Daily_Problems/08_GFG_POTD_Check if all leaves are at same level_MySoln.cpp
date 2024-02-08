/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        //this vector will store the level of each leaf nodes
        vector<int> leafNodes;
        countLevel(root, leafNodes, 1);
        
        int n = leafNodes.size();
        //if all the values are same then return true else false
        for(int i=0; i<n-1; i++){
            if(leafNodes[i] != leafNodes[i+1])
                return false;
        }
        return true;
    }
    void countLevel(Node* node, vector<int> &leafNodes, int level){
        //if it's leaf node insert it's level
        if(node == NULL){
            //which means that we've reached a node which has a single child and other pointer is null
            //so return 
            return;
        }
        if(node->left == NULL && node->right == NULL){
            leafNodes.push_back(level);
            return;
        }
        
        //move to left and right subtree
        countLevel(node->left, leafNodes, level+1);
        countLevel(node->right, leafNodes, level+1);
        
    }
};