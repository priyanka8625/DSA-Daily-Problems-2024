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
    int pseudoPalindromicPaths (TreeNode* root) {
        int pseudoCount=0;
        map<int, int> nodeValCount;
        countPseudoPalindromes(root, pseudoCount, nodeValCount);
        return pseudoCount;
    }
    void countPseudoPalindromes(TreeNode* node, int& pseudoCount, map<int, int> &nodeValCount){
        //if either node->left or node->right is NULL
        if(node == NULL)
            return;
            
        //base condition
        if(node->left == NULL && node->right == NULL){
            //we've reached the leaf node of a path and the leaf node's freq into map
            nodeValCount[node->val]++;
            //calculate no of values whose freq is odd
            int oddParity = 0;
            for(auto& [key, value] : nodeValCount){
                if(value%2 != 0)
                    oddParity++;
            }
            //oddParity represents the no. of nodes which have odd frequencies in the current path
            // if atmost one oddParity exists then it is a palindromic path else no 
            if(oddParity <= 1)
                pseudoCount++;
            
            //backtrack 
            nodeValCount[node->val]--;
            return;
        }
        

        //update current node val's freq in map
        nodeValCount[node->val]++;

        //move to left and right subtrees
        countPseudoPalindromes(node->left, pseudoCount, nodeValCount);
        countPseudoPalindromes(node->right, pseudoCount, nodeValCount);

        //backtrack before moving to last function call
        nodeValCount[node->val]--;
    }
};