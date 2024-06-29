class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        vector<vector<int>> ans(n);
        for(int i=0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
        }
        //apply dfs from each node in ascending order
        for(int i=0; i<n; i++){
            //update i as the ancestor for all the nodes in the path of i
            vector<bool> visited(n, 0);
            dfs(adjList, i, i, ans, visited);
        }
        return ans;
    }
    void dfs(vector<int> adjList[], int ancestor, int curr,vector<vector<int>>& ans, vector<bool>& visited){
        visited[curr] = 1;
        for(int neigh : adjList[curr]){
            if(!visited[neigh]){
                ans[neigh].push_back(ancestor);
                dfs(adjList, ancestor, neigh, ans, visited);
            }
        }
    }
};