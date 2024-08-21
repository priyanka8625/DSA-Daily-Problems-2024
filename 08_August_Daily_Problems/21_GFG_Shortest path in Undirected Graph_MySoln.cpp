class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //use simple BFS instead of dijkstra, as weights are given 1 for all the edges
        //hence BFS will give shortest dist to all nodes from src 
        queue<int> q;
        vector<int> adjList[N];
        vector<int> dist(N, -1);
        vector<int> vis(N, 0);
        for(int i=0; i<M; i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        q.push(src);
        vis[src] = 1;
        dist[src] = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                
                for(int neigh : adjList[curr]){
                    if(!vis[neigh]){
                        dist[neigh] = dist[curr] + 1;
                        vis[neigh] = 1;
                        q.push(neigh);
                    }
                }
            }
        }
        return dist;
    }
};