class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k, vector<int>(k, 0));

        vector<int> rowOrder = generateTopologicalOrder(rowConditions, k);
        vector<int> colOrder = generateTopologicalOrder(colConditions, k);
        if(rowOrder.size()<k || colOrder.size()<k){
            return {};
        }

        unordered_map<int, int> mp;//to store rowOrder's indices
        for(int i=0; i<k; i++){
            mp[rowOrder[i]] = i;
        }
        for(int i=0; i<k; i++){
            ans[mp[colOrder[i]]][i] = colOrder[i];
        }
        return ans;
    }
    vector<int> generateTopologicalOrder(vector<vector<int>>& edges, int k){
        vector<int> adj[k+1];
        vector<int> indeg(k+1, 0);
        queue<int> q;
        vector<int> order;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        for(int i=1; i<=k; i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(int ele : adj[node]){
                if(--indeg[ele] == 0){
                    q.push(ele);
                }
            }
        }
        return order;
    }
};