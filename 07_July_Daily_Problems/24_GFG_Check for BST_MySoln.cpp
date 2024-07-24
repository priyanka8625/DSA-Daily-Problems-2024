class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return bst(root, INT_MIN, INT_MAX);
    }
    bool bst(Node* root, int min, int max){
        if(!root){
            return true;
        }
        if(root->data<=min || root->data>=max){
            return false;
        }
        if(bst(root->left, min, root->data) && bst(root->right, root->data, max)){
            return true;
        }
        return false;
    }
};