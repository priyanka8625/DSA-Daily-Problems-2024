void convert(Node *head, TreeNode *&root) {
    // Your code here
    queue<TreeNode*> q;
    //create root 
    root = new TreeNode(head->data);
    q.push(root);
    while(!q.empty() && head){
        //get current root
        TreeNode* node = q.front();
        q.pop();
        
        if(head->next){
            node->left = new TreeNode(head->next->data);
            q.push(node->left);
            head = head->next;
        }
        if(head->next){
            node->right = new TreeNode(head->next->data);
            q.push(node->right);
            head = head->next;
        }
    }
}