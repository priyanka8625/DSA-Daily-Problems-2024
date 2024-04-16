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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        getNewTree(root, val, 1, depth);
        return root;
    }
    void getNewTree(TreeNode* &root, int &val, int cur, int &depth){
        if(root == NULL)
            return;

        if(cur == depth-1){
            //at this depth create two nodes with value = val 
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            //before adding these into root node, store the references of original left and right subtree
            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            return;
        }
        //else move to the next depth
        getNewTree(root->left, val, cur+1, depth);
        getNewTree(root->right, val,  cur+1, depth);
    }
};