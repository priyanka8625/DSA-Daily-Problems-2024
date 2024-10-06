class Solution {
  public:
    // Function to find the number of islands.
    int row[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int col[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int n, m;
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n=grid.size(), m=grid[0].size();
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '0';//mark visited
        //go through neighbours
        for(int k=0; k<8; k++){
            int newi=i+row[k], newj=j+col[k];
            if(isValid(newi, newj) && grid[newi][newj]=='1')
                dfs(newi, newj, grid);
        }
    }
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
};