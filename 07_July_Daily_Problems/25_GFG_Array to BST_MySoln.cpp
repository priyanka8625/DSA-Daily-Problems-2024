class Solution {
  public:
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        return arrayToBST(nums, 0, nums.size()-1);
    }
    Node* arrayToBST(vector<int>& nums, int start, int end){
        if(start>end){
            return NULL;
        }
        
        int mid = start+(end-start)/2;
        Node* root = new Node(nums[mid]);
        root->left = arrayToBST(nums, start, mid-1);
        root->right = arrayToBST(nums, mid+1, end);
        
        return root;
    }
};
