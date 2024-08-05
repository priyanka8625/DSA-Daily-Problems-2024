class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int, int> mp;//to store nodes at respective horizontal distance from the root
        //do level order traversal to get correct horizontal distnace of each node
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node *node = q.front().first;
            int distance = q.front().second;
            q.pop();
            
            //update the distance value
            mp[distance] = node->data;
            
            //consider next level children of current node
            if(node->left) q.push({node->left, distance-1});
            if(node->right) q.push({node->right, distance+1});
        }
        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};