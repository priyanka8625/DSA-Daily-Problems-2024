class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        map<string,int> m;
        int n=accounts.size();
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])!=m.end()){
                    ds.unionBySize(i,m[accounts[i][j]]);
                }
                else{
                   
                    m[accounts[i][j]]=i;
                }
            }
        }
        vector<vector<string>> ans(n);
        
        for(auto it:m){
            string id=it.first;
            int key=it.second;
            key=ds.findUPar(key);
            string name=accounts[key][0];
            if(ans[key].size()==0){
                ans[key].push_back(name);
            }
            ans[key].push_back(id);
            
        }
        
        vector<vector<string>> ans2;
        
        for(int i=0;i<n;i++){
            if(ans[i].size()!=0){
                ans2.push_back(ans[i]);
            }
        }
        
        
        
        
    
        return ans2;
    }
};