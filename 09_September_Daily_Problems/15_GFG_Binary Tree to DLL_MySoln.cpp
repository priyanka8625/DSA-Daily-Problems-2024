class Solution {
  public:
    Node *prev=NULL;
    Node* bToDLL(Node* root) {
        // code here
        if(!root)
            return NULL;
        
        Node *head = NULL;
        head = bToDLL(root->left);
        
        if(prev == NULL){
            head = root;
        }else{
            prev->right = root;
            root->left = prev;
        }
        
        prev = root;
        
        bToDLL(root->right);
        return head;
    }
};