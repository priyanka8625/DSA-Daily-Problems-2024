class Solution {
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return check(root)!=-1;
    }
    int check(Node *root){
        if(!root)
            return 0;
        
        //traverse the left and right subtree
        int left_sum = check(root->left);
        int right_sum = check(root->right);
        if(left_sum==-1 || right_sum==-1){
            //one of the subtrees is not sum_tree
            return -1;
        }else if(left_sum==0 && right_sum==0){
            //it's a leaf node
            return root->data;
        }else if(left_sum+right_sum == root->data){
            return left_sum+right_sum+root->data;
        }
        return -1;
    }
};
