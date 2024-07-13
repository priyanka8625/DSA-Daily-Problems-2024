class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        //using dikstra
        vector<pair<int, int>> adj[n+1];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v=edges[i][1], wt=edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> parent(n+1, -1);
        vector<int> dist(n+1, INT_MAX);
        vector<bool> explored(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        //initialize
        dist[1] = 0;
        parent[1] = -1;
        pq.push({0, 1});//distance,node
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(explored[node])
                continue;
            
            //explore neighbours
            explored[node] = 1;
            for(int j=0; j<adj[node].size(); j++){
                int neighbour = adj[node][j].first;
                int weight = adj[node][j].second;
                if(!explored[neighbour] && dist[node]+weight < dist[neighbour]){
                    dist[neighbour] = dist[node] + weight;
                    parent[neighbour] = node;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        
        vector<int> path;
        if(parent[n]==-1){
            return {-1};
        }
        int i=n;
        while(i!=-1){
            path.push_back(i);
            i = parent[i];
        }
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};
