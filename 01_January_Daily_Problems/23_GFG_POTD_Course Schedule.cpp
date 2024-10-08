class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        // int vis[n]={0};
        int indeg[n]={0};
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
               indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int  node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(ans.size()!=n){
            vector<int>temp;
            return temp;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};