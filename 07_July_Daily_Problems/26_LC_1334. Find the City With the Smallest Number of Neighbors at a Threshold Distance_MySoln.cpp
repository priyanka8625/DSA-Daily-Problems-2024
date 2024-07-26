class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //using floyd warshall to find the shortest paths between all the nodes
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        //initialize adj matrix
        for(int i=0; i<n; i++){
            adj[i][i] = 0;//digonal entries
        }
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v=edges[i][1], wt=edges[i][2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        //now consider each node between 0->n as intermediate node and find the shortest path
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX)
                        continue;
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        //now find the no. of nodes that are at a distance <= threshold for each node
        int node=-1, minNeighs=INT_MAX;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(i==j && adj[i][j]==INT_MAX){//excluding diagonals and non-edges
                    continue;
                }
                if(adj[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=minNeighs){
                minNeighs = count;
                node = i;
            }
        }
        return node;
    }
};