class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<int, vector<int>> adj;
        unordered_set<int> vis;
        convertToGraph(root, adj);
        
        queue<int> q;
        q.push(target);
        int timer = 0;
        vis.insert(target);
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                
                for(int neigh : adj[curr]){
                    if(vis.find(neigh) == vis.end()){
                        q.push(neigh);
                        vis.insert(neigh);
                    }
                }
            }
            timer++;
        }
        return --timer;
    }
    void convertToGraph(Node* root, unordered_map<int, vector<int>>& adj){
        if(!root){
            return;
        }
        
        if(root->left){
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
        }
        if(root->right){
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
        }
        
        convertToGraph(root->left, adj);
        convertToGraph(root->right, adj);
    }
};