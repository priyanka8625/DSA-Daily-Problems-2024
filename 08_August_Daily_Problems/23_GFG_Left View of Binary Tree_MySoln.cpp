void dfs(Node* root, vector<int>& ans, int level){
    if(!root)
        return;
    
    //no node present at current level in ans
    if(ans.size() == level-1){
        ans.push_back(root->data);
    }
    
    dfs(root->left, ans, level+1);
    dfs(root->right, ans, level+1);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   dfs(root, ans, 1);
   return ans;
}

