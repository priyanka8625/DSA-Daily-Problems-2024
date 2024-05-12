class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2));

        for(int row=0; row<n-2; row++){
            for(int col=0; col<n-2; col++){
                //take the max element of the current 3x3 grid
                int maxEle = 0;
                for(int i=row; i<row+3; i++){
                    for(int j=col; j<col+3; j++){
                        maxEle = max(maxEle, grid[i][j]);
                    }
                }
                ans[row][col] = maxEle;
            }
        }
        return ans;
    }
};