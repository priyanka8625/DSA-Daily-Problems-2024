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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        //extract all the leaf nodes of root1 in leaves1
        extractLeaves(root1, leaves1);
        //extract all the leaf nodes of root2 in leaves2
        extractLeaves(root2, leaves2);
        //compare the sequence and their equality 
        if(leaves1.size() != leaves2.size())
            return false;

        int i=0;
        while(i<leaves1.size()){
            if(leaves1[i] != leaves2[i]){
                //it means that leaves are not equal
                return false;
            }
            //if leaves are equal, compare next leaves
            i++;
        }
        //after loop it's clear that all the leaves are equal
        return true;
    }
    void extractLeaves(TreeNode* root, vector<int> &leaves){
        if(root->left==NULL && root->right==NULL){
            leaves.push_back(root->val);
            return;
        }
        //move to the left child
        if(root->left != NULL)//for cases where, there's no element at left side of a node and there is a right node, in such cases for left call we'll access left of null, so first check
            extractLeaves(root->left, leaves);
        //move to right child
        if(root->right != NULL)
            extractLeaves(root->right, leaves);
    }
};
