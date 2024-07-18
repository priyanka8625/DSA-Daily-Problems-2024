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
    int countPairs(TreeNode* root, int distance) {
        vector<TreeNode*> leaves;
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        vector<TreeNode*> path;
        findPathToLeaves(root, leaves, mp, path);
        //now find distance between the leaf node pairs
        int count=0;
        for(int i=0; i<leaves.size(); i++){
            for(int j=i+1; j<leaves.size(); j++){
                vector<TreeNode*> path1 = mp[leaves[i]];
                vector<TreeNode*> path2 = mp[leaves[j]];
                for(int k=0; k<min(path1.size(), path2.size()); k++){
                    if(path1[k]!=path2[k]){
                        int dist = (path1.size()-k) + (path2.size()-k);
                        if(dist<=distance){
                            count++;
                        }
                        break;
                    }
                }
            }
        }
        return count;
    }
    void findPathToLeaves(TreeNode* root, vector<TreeNode*>& leaves, unordered_map<TreeNode*, vector<TreeNode*>>& mp, vector<TreeNode*>& path){
        if(!root){
            return;
        }
        path.push_back(root);
        if(!root->left && !root->right){
            leaves.push_back(root);
            mp[root] = path;
            path.pop_back();
            return;
        }
        findPathToLeaves(root->left, leaves, mp, path);
        findPathToLeaves(root->right, leaves, mp, path);
        path.pop_back();
    }
};