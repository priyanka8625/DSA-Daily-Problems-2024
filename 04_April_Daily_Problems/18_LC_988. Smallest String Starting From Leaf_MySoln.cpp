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
    string smallestFromLeaf(TreeNode* root) {
        string ans="";
        string temp = "";
        getSmallest(root, ans, temp);
        return ans;
    }
    void getSmallest(TreeNode* root, string &ans, string temp){
        //base condn
        if(root == NULL){
            return;
        }
        if(!root->left && !root->right){
            //compare the temp string with ans
            temp = (char)(root->val + 'a') + temp;
            if(ans == "" || temp < ans){
                ans = temp;
            }
            return;
        }

        //add current character to the front of the string so that we get string starting from leaf 
        //when root == leaf node
        temp = (char)(root->val + 'a') + temp;
        //left subtree
        getSmallest(root->left, ans, temp);
        //right subtree
        getSmallest(root->right, ans, temp);
    }
};