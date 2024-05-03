/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      // Your code here
      if(k==0)
        return {root->data};
      //we'll simply use recursion here
      vector<int> ans;
      getKNodes(root, k, ans);
      return ans;
    }
    void getKNodes(struct Node* root, int k, vector<int> &ans){
        if(root == NULL)
            return;
        if(k==0){
            //insert root's data into ans
            ans.push_back(root->data);
            return;
        }
        //traverse the left and right subtree unless k==0
        getKNodes(root->left, k-1, ans);
        getKNodes(root->right, k-1, ans);
    }
};