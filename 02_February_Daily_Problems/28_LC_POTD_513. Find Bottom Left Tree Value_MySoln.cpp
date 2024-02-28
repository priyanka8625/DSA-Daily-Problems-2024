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
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = 0, leftValue = -1, level=1;
        getBottomLeft(root, leftValue, maxLevel, level);
        return leftValue;
    }
    void getBottomLeft(TreeNode *root, int &leftValue, int &maxLevel, int level){
        if(root == NULL)
            return;
        //first, check the level of current node is greater than the maxLevel value
        if(maxLevel < level){
            maxLevel = level;
            leftValue = root->val;
        }
        //go down in the left subtree, if exists to find the leftmost bottom leaf
        getBottomLeft(root->left, leftValue, maxLevel, level+1);
        //same for right subtree
        getBottomLeft(root->right, leftValue, maxLevel, level+1);
    }
};