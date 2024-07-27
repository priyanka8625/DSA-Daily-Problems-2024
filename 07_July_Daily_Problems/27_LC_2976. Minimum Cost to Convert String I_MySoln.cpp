class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<vector<int>> adj(26, vector<int>(26, INT_MAX));
        for(int i=0; i<n; i++){
            int u = original[i]-'a', v=changed[i]-'a', wt=cost[i];
            adj[u][v]= min(adj[u][v], wt);//to avoid larger overwrites
        }
        for(int i=0; i<26; i++){
            if(adj[i][i]==INT_MAX)
                adj[i][i] = 0;
        }
        //apply floyd warshall
        getShortestPaths(adj, 26);

        //traverse both the strings and get min no of operations to convert s->t
        int len=source.length();
        long long ans=0;
        for(int i=0; i<len; i++){
            int minSteps = adj[source[i]-'a'][target[i]-'a'];
            if(minSteps==INT_MAX)
                return -1;
            ans += minSteps;
        }
        return ans==0?-1:ans;
    }
    void getShortestPaths(vector<vector<int>>& adj, int n){
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX)
                        continue;

                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
    }
};
