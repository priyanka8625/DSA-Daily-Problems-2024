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
    // add the levels of left and right subtree and we'll get the longest path between any two nodes
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        getDiameter(root, diameter);//this function returns the height of the tree node passed to it
        return diameter;
    }
    int getDiameter(TreeNode* root, int &diameter){
        if(root == NULL)
            return 0;//height of an empty tree is always zero

        int leftHeight = getDiameter(root->left, diameter);
        int rightHeight = getDiameter(root->right, diameter);
        //calculate the diameter at the current node and update diameter variable accordingly
        //AWK, the diameter at each node will be the sum of the heights of it's left & right subtrees
        diameter = max(diameter, leftHeight+rightHeight);

        //return the height of the current subtree to previous function call
        return max(leftHeight, rightHeight)+1;
    }
};