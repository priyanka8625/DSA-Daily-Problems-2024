/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        if(!root) return {};
        vector<int> ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int currsum=0;
            for(int i=0;i<size;i++){
                Node * curr = q.front();
                q.pop();
                while(curr){
                    currsum+=(curr->data);
                    if(curr->left){
                        q.push(curr->left);
                    }
                    curr= curr->right;
                }
                
            }
            ans.push_back(currsum);
        }
        return ans;
        
    }
};