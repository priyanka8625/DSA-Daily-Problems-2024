/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        //apply recursion
        vector<vector<int>> ans;
        vector<int> temp;
        getPaths(root, ans, temp);
        return ans;
    }
    //dfs
    void getPaths(Node* node, vector<vector<int>> &ans, vector<int> temp){
        if(node == NULL)
            return;
        //if leaf node
        if(node->left==NULL && node->right==NULL){
            temp.push_back(node->data);
            ans.push_back(temp);
            return;
        }
        //insert the current node into temp and traverse upto leaf node
        temp.push_back(node->data);
        getPaths(node->left, ans, temp);
        getPaths(node->right, ans, temp);
    }
};
