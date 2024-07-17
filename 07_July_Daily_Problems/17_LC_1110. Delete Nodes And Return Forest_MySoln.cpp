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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        vector<TreeNode*> ans;
        for(int i=0; i<to_delete.size(); i++){
            s.insert(to_delete[i]);
        }
        identifyNodes(root, s);
        if(root->val != -1) ans.push_back(root);
        removeNodes(root, NULL, ans);
        return ans;
    }
    void removeNodes(TreeNode* root, TreeNode* parent, vector<TreeNode*>& ans){
        if(!root){
            return;
        }
        if(root->val == -1){
            if(parent && parent->left && parent->left->val == root->val){
                parent->left = NULL;
            }else if(parent && parent->right && parent->right->val==root->val){
                parent->right = NULL;
            }
        }
        if(parent && parent->val == -1 && root->val != -1){
            ans.push_back(root);
        }
        removeNodes(root->left, root, ans);
        removeNodes(root->right, root, ans);
    }
    void identifyNodes(TreeNode* root, unordered_set<int>& s){
        if(!root){
            return;
        }
        if(s.find(root->val)!=s.end()){
            root->val = -1;
        }
        identifyNodes(root->left, s);
        identifyNodes(root->right, s);
    }
};