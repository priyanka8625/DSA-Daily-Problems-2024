class Solution {
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        vector<int> ans;
        getAncestors(root, target, ans);
        return ans;
    }
    bool getAncestors(Node* &root, int &target, vector<int>& ans){
        if(!root)
            return false;
        if(root->data == target)
            return true;
            
        if(getAncestors(root->left, target, ans) || getAncestors(root->right, target, ans))
            ans.push_back(root->data);
    }
};
