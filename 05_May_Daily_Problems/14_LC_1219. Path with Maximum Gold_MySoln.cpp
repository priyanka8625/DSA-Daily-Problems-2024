class Solution {
    private:
    int rows[4] = {0, 0, -1, 1};//transformations for left right up down of rows
    int cols[4] = {-1, 1, 0, 0};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxSum=0, nRows = grid.size(), nCols=grid[0].size();
        for(int i=0; i<nRows; i++){
            for(int j=0; j<nCols; j++){
                if(grid[i][j]){
                    //if gold is present at current cell
                    getMaxGold(grid, i, j, maxSum, 0);
                }
            }
        }
        return maxSum;
    }
    void getMaxGold(vector<vector<int>>& grid, int i, int j, int& maxSum, int sum){
        //visit current cell and add it's gold to sum
        int gold = grid[i][j];
        grid[i][j] = 0;//visit the cell
        sum += gold;

        //explore the four paths Left, right, up n down
        for(int k=0; k<4; k++){
            if(isValid(grid, i+rows[k], j+cols[k]) && grid[i+rows[k]][j+cols[k]]){
                //apply recursion to find the gold sum
                getMaxGold(grid, i+rows[k], j+cols[k], maxSum, sum);
            }
            //get the maxSum after each dfs traversal
            maxSum = max(maxSum, sum); 
        }
        //backtrack
        grid[i][j]=gold;
    }
    bool isValid(vector<vector<int>>& grid, int i, int j){
        int nRows = grid.size(), nCols=grid[0].size();
        return !(i<0 || i>=nRows || j<0 || j>=nCols);
    }
};