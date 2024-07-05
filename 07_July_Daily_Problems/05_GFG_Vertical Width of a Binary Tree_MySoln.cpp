class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int maxPos, minPos;
    int verticalWidth(Node* root) {
        // code here
        if(!root) return 0;
        
        maxPos = INT_MIN;
        minPos = INT_MAX;
        getPositions(root, 0);
        return maxPos-minPos+1;
    }
    void getPositions(Node* root, int pos){
        if(!root)
            return;
        getPositions(root->left, pos-1);
        getPositions(root->right, pos+1);
        
        minPos = min(minPos, pos);
        maxPos = max(maxPos, pos);
    }
};