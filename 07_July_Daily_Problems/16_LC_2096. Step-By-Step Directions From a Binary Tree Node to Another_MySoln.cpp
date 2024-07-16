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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string source="", dest="";
        //find root->source path
        dfs(root, startValue, source);
        //find root->dest path
        dfs(root, destValue, dest);
        //remove logest common prefix between the two paths
        int i=0;
        while(i<source.length() && i<dest.length() && source[i] == dest[i]){
            i++;
        }
        //now append source + dest string in ans (make sure to update source string to all Up's)
        string ans="";
        int index = i;
        while(index<source.length()){
            ans.push_back('U');
            index++;
        }
        index = i;
        while(index<dest.length()){
            ans.push_back(dest[index]);
            index++;
        }
        return ans;
    }
    bool dfs(TreeNode* root, int target, string& ans){
        if(!root){
            return false;
        }
        if(root->val == target){
            return true;
        }
        ans.push_back('L');
        if(dfs(root->left, target, ans))
            return true;
        ans.pop_back();
        ans.push_back('R');
        if(dfs(root->right, target, ans))
            return true;
        ans.pop_back();
        return false;
    }
};