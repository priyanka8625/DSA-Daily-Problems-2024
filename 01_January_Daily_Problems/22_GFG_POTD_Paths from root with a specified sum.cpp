
/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> temp;
        getPaths(root, sum, 0, temp, ans);
        return ans;
    }
    
    void getPaths(Node *node, int &sum, int tempSum, vector<int> &temp, vector<vector<int>>& ans){
        if(node == NULL){
            return;
        }
        
        tempSum += node->key;
        temp.push_back(node->key);
        if(tempSum == sum && temp.size()!=0){
            ans.push_back(temp);
        }
        
        //move to left
        getPaths(node->left, sum, tempSum, temp, ans);
        getPaths(node->right, sum, tempSum, temp, ans);
        
        temp.pop_back();
        
    }
};