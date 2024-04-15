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
    int sumNumbers(TreeNode* root) {
        int sum=0, number=0;
        getSum(root, sum, number);
        return sum;
    }
    void getSum(TreeNode* root, int &sum, int number){
        if(root == NULL)
            return;
        if(!root->left && !root->right){
            sum += (number*10 + root->val);
            return;
        }
        
        //add current value in number
        number = number*10 + root->val;
        getSum(root->left, sum, number);
        getSum(root->right, sum, number);
    }
};