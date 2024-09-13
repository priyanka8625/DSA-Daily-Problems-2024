class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node)
            return;
        
        Node *left=node->left, *right = node->right;
        node->right = left;
        node->left = right;
        
        mirror(node->left);
        mirror(node->right);
    }
};