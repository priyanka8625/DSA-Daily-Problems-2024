/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    //to get the reverse of level order traverse i.e. from the deepest level to root node
    //we can do this by using a queue just like we do in level oredr traversal but 
    //here first we'll insert the right child of each node and add the it's value into a vector
    //so that when we reverse the vector we get reverse level order traversal
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        
        ans.push_back(node->data);
        
        if(node->right){
            q.push(node->right);
        }
        if(node->left){
            q.push(node->left);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}