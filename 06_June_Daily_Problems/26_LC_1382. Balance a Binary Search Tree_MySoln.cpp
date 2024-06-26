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
    TreeNode* balanceBST(TreeNode* root) {
        //1. convert tree into sorted array
        vector<int> nodes;
        getNodes(root, nodes);
        //2. convert the sorted array into height balanced tree
        int n = nodes.size();
        return getBalancedTree(nodes, 0, n-1);
    }
    TreeNode* getBalancedTree(vector<int>& nodes, int start, int end){
        if(start>end)
            return NULL;
        
        //get the root node of current start->end range
        int mid = start+(end-start)/2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = getBalancedTree(nodes, start, mid-1);//left subtree= eles < mid
        node->right = getBalancedTree(nodes, mid+1, end);//right = eles>mid

        return node;
    }
    void getNodes(TreeNode* &root, vector<int>& nodes){
        if(root==NULL)
            return;
        
        getNodes(root->left, nodes);
        nodes.push_back(root->val);
        getNodes(root->right, nodes);
    }
};