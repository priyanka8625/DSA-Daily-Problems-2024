/**/
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


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      queue<Node*> elements;
      vector<int> ans;
      elements.push(root);
      while(!elements.empty()){
          Node *ele = elements.front();
          elements.pop();
          ans.push_back(ele->data);
          if(ele->left!= NULL)
            elements.push(ele->left);
          if(ele->right != NULL)
            elements.push(ele->right);
      }
      return ans;
    }
};