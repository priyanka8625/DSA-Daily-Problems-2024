class Solution {
  public:
    Node* last = NULL;
    void populateNext(Node *root) {
        // code here
        inorder(root);
    }
    void inorder(Node* root){
        if(!root)
            return;
            
        inorder(root->right);
        if(last != NULL)
            root->next = last;
        last = root;
        inorder(root->left);
    }
};