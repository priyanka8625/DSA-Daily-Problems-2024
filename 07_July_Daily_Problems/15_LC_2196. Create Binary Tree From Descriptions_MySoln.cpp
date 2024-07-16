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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = NULL;
        unordered_map<int, pair<TreeNode*, TreeNode*>> mp;
        //find root
        int n = descriptions.size();
        for(int i=0; i<n; i++){
            int parent = descriptions[i][0], child=descriptions[i][1], isLeft=descriptions[i][2];
            //check if parent or child are already there in mp
            TreeNode* par=NULL, *ch=NULL;
            if(mp.find(parent) != mp.end()){
                par = mp[parent].first;
            }else{
                par = new TreeNode(parent);
                mp[parent] = {par, NULL};
            }
            if(mp.find(child) != mp.end()){
                ch = mp[child].first;
            }else{
                ch = new TreeNode(child);
            }
            //update child's parent 
            mp[child] = {ch, par};

            if(isLeft){
                par->left = ch;
            }else{
                par->right = ch;
            }
        }
        //find root
        for(auto it : mp){
            if((it.second).second == NULL){
                root = (it.second).first;
                break;
            }
        }
        return root;
    }
};