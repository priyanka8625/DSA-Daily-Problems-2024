class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        vector<bool> visited(v+1, 0);
        int total = 0;
        //create adjacency list
        vector<vector<int>> adjList(v+1);
        for(int i=0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        //find the dfs traversal for eac component
        for(int i=1; i<=v; i++){
            if(!visited[i]){
                //find dfs
                vector<int> temp;
                dfs(adjList, i, visited, temp);
                
                //compare if each node in the above dfs is connected to all the other nodes 
                // in order to form a connected component
                bool flag = true;
                for(int node : temp){
                    //compare the no. of elements in dfs except the current element
                    //and the no of adjacent elements of current element
                    if(temp.size()-1 != adjList[node].size()){
                        // if not equal the don't count this as connected component
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    total++;
            }
        }
        return total;
    }
    void dfs(vector<vector<int>>& adjList, int node, vector<bool>& visited, vector<int>& temp){
        //visit current node
        visited[node] = 1;
        temp.push_back(node);
        
        //visit adjacent nodes
        for(int ele : adjList[node]){
            if(!visited[ele])
                dfs(adjList, ele, visited, temp);
        }
    }
    
};