/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    
    public:
    Node* lca(Node* root, int a, int b){
        if(!root || root->data==a || root->data==b){
            return root;
        }
        
        Node* left=lca(root->left, a, b);
        Node* right=lca(root->right, a, b);
        
        if(!left){
            return right;
        }else if(!right){
            return left;
        }else{
            return root;
        }
    }
    bool count(Node* node, int a, int b, int& d){
        if(!node) return false;
        d++;
        if(node->data==a || node->data==b){
            return true;
        }
        if(count(node->left, a, b, d) || count(node->right, a, b, d)){
            return true;
        }
        d--;
        return false;
    }
    int findDist(Node* root, int a, int b) {
        // code here
        Node* node=lca(root, a, b);
        int d1=0, d2=0;
        count(node->left, a, b, d1);
        count(node->right, a, b, d2);
        return d1+d2;
    }
    
};
