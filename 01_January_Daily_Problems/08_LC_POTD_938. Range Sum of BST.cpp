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
    // we'll move in inorder traversal
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        sumOfNodes(root, low, high, sum);
        return sum;
    }
    void sumOfNodes(TreeNode* node, int low, int high, int &sum) {
        if(node == NULL){
            return;
        }
        //move to left
        sumOfNodes(node->left, low, high, sum);
        //check for root value
        if(node->val >= low && node->val <=high)
            sum += node->val;
        //now move to right nodes
        sumOfNodes(node->right, low, high, sum);
    }
};