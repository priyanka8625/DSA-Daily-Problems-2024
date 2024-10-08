class Solution {
public:

    int cnt = 0;
    
    void make_adj(vector<int>adj[], vector<vector<int>>&edges){
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u); //bidirectional edge;
        }
        
        return;
        
    }
    
    
    int f(int node, vector<int>adj[], vector<int>&visited){
        
        visited[node] = 1;
        
        int total_nodes = 0;
        
        for(auto it: adj[node]){
            if(!visited[it]){
               total_nodes += f(it, adj, visited);
            }
        }
        
        
        
        total_nodes += 1;
        
        if((node != 1) && (total_nodes %2 == 0)) cnt++;
        
        return total_nodes;
        
    }
    

	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>adj[n+1];
	    make_adj(adj, edges);
	    vector<int>visited(n+1, 0);
	    
	    int dummy = f(1, adj, visited);
	    
	    
	    return cnt;
	}
};