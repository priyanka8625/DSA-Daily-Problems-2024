
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        //as it's a binary tree, we can't use the traversal techniques of in, pre or post order 
        //as they mean nothing for a binary tree as it's not a binary search tree
        //hence we'll use level order traversal for which we'll need a queue
        queue<Node*> q;
        vector<int> ans;
        //insert the root into q
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            //check if the node is not null
            if(node){
                ans.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }else{
                ans.push_back(-1);//means null child
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       //convert the level order traversal into binary tree
       Node* root = new Node(A[0]);
       queue<Node*> q;
       q.push(root);
       int i=1;//left child of root
       while(!q.empty() && i<A.size()){
           Node *node = q.front();
           q.pop();
           
           if(A[i]==-1){
               //left child is null
               node->left = NULL;
           }else{
               //left child is present
               node->left = new Node(A[i]);
               q.push(node->left);
           }
           
           if(A[i+1] == -1){
               //right child is null
               node->right = NULL;
           }else{
               node->right = new Node(A[i+1]);
               q.push(node->right);
           }
           //move i to point the children of next node in level order traversal
           i+=2;
       }
       return root;
    }
    
};