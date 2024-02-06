/*struct NodeGiven a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes. A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly k.
{
	int data;
	Node *left, *right;
};*/
class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
         void pkd(Node* root,int k,set<int> &s,int i,int x)
    {
        if(root==NULL)
        return ;
        
        if((root->left==NULL && root->right==NULL) && i==k)
        s.insert(x);
        
        pkd(root->left,k,s,i+1,x);
        pkd(root->right,k,s,i+1,x);
     }
    
    int printKDistantfromLeaf(Node* root, int k)
    {
        //Add your code here. 
    
    
     
        set<int> s;
    if (root == nullptr)
        return s.size();

    pkd(root, k, s, 0, root->data);

    
    int leftResult = printKDistantfromLeaf(root->left, k);
    int rightResult = printKDistantfromLeaf(root->right, k);

    return s.size() + leftResult + rightResult;
    }
    
};