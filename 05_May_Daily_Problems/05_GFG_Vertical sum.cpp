/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        //let's assign each node a key which will identify it's position and the same position values 
        //will be added 
        map<int, int> sums;
        getLevelSums(root, sums, 0);//root level will be 0;
        vector<int> ans;
        for(auto &it : sums)
            ans.push_back(it.second);//add sums into ans
        
        return ans;
    }
    void getLevelSums(Node* root, map<int, int>&sums, int level){
        if(root == NULL)
            return;
        
        //we'll first add the leftmost level values 
        getLevelSums(root->left, sums, level-1);
        
        //now add the current value into it's level sum
        sums[level] += root->data;
        
        //now find the rightmost level values 
        getLevelSums(root->right, sums, level+1);
    }
};