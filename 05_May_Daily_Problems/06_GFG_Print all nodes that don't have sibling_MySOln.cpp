//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

vector<int> noSibling(Node* root)
{
    // code here
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        
        //check if the left and right nodes are present
        int left=-1, right=-1;
        if(node->left)
            left = node->left->data;
        if(node->right)
            right = node->right->data;
        
        //check if the two siblings are present or not
        if(left==-1 && right!=-1){
            //insert the right node
            ans.push_back(right);
            q.push(node->right);
        }else if(left!=-1 && right==-1){
            //insert left
            ans.push_back(left);
            q.push(node->left);
        }else if(left!=-1 && right!=-1){
            //insert both of them into queue 
            q.push(node->left);
            q.push(node->right);
        }
        //if both are -1 then continue with the next node in queue
    }
    if(ans.size()==0)
        return {-1};
    sort(ans.begin(), ans.end());
    return ans;
}