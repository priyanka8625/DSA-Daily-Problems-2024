
class Solution {
  public:
    int isCircle(vector<string> &arr) {
        // code here
        //we will use the algorithm to find eulerian circuit
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        vector<int> outdeg(26, 0);
        int N = arr.size();
        
        //form graph
        for(int i=0; i<N; i++){
            string temp = arr[i];
            int u = temp[0]-'a';
            int v = temp[temp.length()-1]-'a';
            adj[u].push_back(v);
            outdeg[u]++;
            indeg[v]++;
        }
        
        //now to form a cycle indeg must be == outdeg
        for(int i=0; i<26; i++){
            if(indeg[i]!=outdeg[i])
                return 0;
        }
        //AND all the nodes must be present in a single component
        vector<int> vis(26, 0);
        
        for(int i=0; i<26; i++){
            if(outdeg[i]!=0){
                dfs(adj, i, vis);
                break;
            }
        }
        
        for(int i=0; i<26; i++){
            if(indeg[i]!=0 && vis[i]==0)
                return 0;
        }
        return 1;
    }
    void dfs(vector<vector<int>>& adj, int start, vector<int>& vis){
        vis[start]=1;
        for(int neigh : adj[start]){
            if(!vis[neigh]){
                dfs(adj, neigh, vis);
            }
        }
    }
};