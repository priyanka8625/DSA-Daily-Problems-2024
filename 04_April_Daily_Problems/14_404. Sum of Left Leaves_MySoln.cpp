/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
            return 0;
        return getSum(root);
    }
    int getSum(TreeNode* root){
        //base condition will be 
        // 1.when root is NULL then return 0
        if(root == NULL)
            return 0; 

        //if left subtree is present traverse it to get the leaf node
        int left=0, right=0;
        if(root->left){
            if(root->left->left==NULL && root->left->right==NULL)
                left = root->left->val;
            else
                left = getSum(root->left);
        }
        right = getSum(root->right);

        return left+right;
    }
};