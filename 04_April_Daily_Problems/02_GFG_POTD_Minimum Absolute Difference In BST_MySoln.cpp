/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
    public:
    int absolute_diff(Node *root)
    {
        //Your code here
        int minDiff=INT_MAX;
        vector<int> nodes;
        inorder(root, nodes);
        for(int i=0; i<nodes.size()-1; i++){
            minDiff = min(nodes[i+1] - nodes[i], minDiff);
        }
        return minDiff;
    }
    void inorder(Node* root, vector<int>& nodes){
        if(root == NULL)
            return;
        
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
    }
};