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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();//curr level size 
            long long sum=0;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            levelSum.push_back(sum);
        }
        
        sort(levelSum.rbegin(), levelSum.rend());
        return (k<=levelSum.size())? levelSum[k-1] : -1;
    }
    
};