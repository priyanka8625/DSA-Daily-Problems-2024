class Solution {
public:
    int t[1002][1002];
    int n, m;
    int r[3] = {-1, 0, 1};
    int c[3] = {1, 1, 1,};
    int maxMoves(vector<vector<int>>& grid) {
        int count=0;
        n = grid.size(), m=grid[0].size();
        memset(t, -1, sizeof(t));
        
        for(int i=0; i<n; i++){
            count = max(count, findMoves(grid, i, 0));
        }
        return count;
    }
    int findMoves(vector<vector<int>>& grid, int row, int col){
        if(t[row][col] != -1)
            return t[row][col];

        int count=0;
        for(int k=0; k<3; k++){
            int i=r[k]+row, j=c[k]+col;
            if(valid(i, j) && grid[row][col] < grid[i][j]){
                count = max(count, 1 + findMoves(grid, i, j));
            }
        }
        t[row][col] = count;
        return count;
    }
    bool valid(int row, int col){
        return row>=0 && row<n && col>=0 && col<m;
    }
};