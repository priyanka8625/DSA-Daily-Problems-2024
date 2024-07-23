class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> bst1, bst2;
        inorder(root1, bst1);
        inorder(root2, bst2);
        vector<int> ans;
        mergeSortedArrs(bst1, bst2, ans);
        return ans;
    }
    void inorder(Node* root, vector<int>& nums){
        if(!root){
            return;
        }
        
        inorder(root->left, nums);
        nums.push_back(root->data);
        inorder(root->right, nums);
    }
    void mergeSortedArrs(vector<int>& bst1, vector<int>& bst2, vector<int>& ans){
        int n=bst1.size(), m=bst2.size();
        int left=0, right=0;
        while(left<n && right<m){
            if(bst1[left]<=bst2[right]){
                ans.push_back(bst1[left]);
                left++;
            }else{
                ans.push_back(bst2[right]);
                right++;
            }
        }
        while(left<n){
            ans.push_back(bst1[left]);
            left++;
        }
        while(right<m){
            ans.push_back(bst2[right]);
            right++;
        }
    }
};