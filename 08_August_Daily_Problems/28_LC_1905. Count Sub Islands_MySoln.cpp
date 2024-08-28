class Solution {
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int n, m;
    bool isIsland=1;
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1 && grid1[i][j]==1){
                    isIsland = 1;
                    count(grid1, grid2, i, j);
                    ans += isIsland;
                }
            }
        }
        return ans;
    }
    void count(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){
        grid2[i][j] = 0;

        for(int k=0; k<4; k++){
            int newi=i+row[k], newj=j+col[k];
            if(isValid(newi, newj)){
                if(grid1[newi][newj]==1 && grid2[newi][newj]==1){
                    count(grid1, grid2, newi, newj);
                }else if(grid1[newi][newj]==0 && grid2[newi][newj]==1){
                    isIsland=0;
                }
            }
        }
    }
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
};