class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(!root){
            return NULL;
        }
        
        Node *left= RemoveHalfNodes(root->left);
        Node* right = RemoveHalfNodes(root->right);
        root->left = left;
        root->right = right;
        
        if(!left && !right){
            return root;//leaf node
        }else if(left && !right){
            return left;
        }else if(!left && right){
            return right;
        }
        
        return root;
    }
};
