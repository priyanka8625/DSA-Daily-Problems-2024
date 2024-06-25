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
    TreeNode* bstToGst(TreeNode* root) {
        int maxNodeSum=0;
        refactorBST(root, maxNodeSum);
        return root;
    }
    void refactorBST(TreeNode* &root, int &sum){
        if(root == NULL)
            return;
        
        //first traverse right subtree, then update root, then left to get max node's sum at each call
        refactorBST(root->right, sum);
        //update root's value with maximum node's sum having val>currNode
        root->val = sum + root->val;
        sum = root->val;//update sum with max Node's Sum 
        //traverse left subtree with the sum of max nodes till now
        refactorBST(root->left, sum);
    }
};