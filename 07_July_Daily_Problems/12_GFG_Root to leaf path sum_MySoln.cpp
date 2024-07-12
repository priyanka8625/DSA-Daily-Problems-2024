class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(!root){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(target-root->data==0)
                return true;
            return false;
        }
        return hasPathSum(root->left, target-root->data) || hasPathSum(root->right, target-root->data);
    }
};