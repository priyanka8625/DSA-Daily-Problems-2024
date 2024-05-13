class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int nrows = grid.size(), ncols = grid[0].size();
        
        // 1. Flip rows if necessary
        for(int i = 0; i < nrows; i++){
            // If the first bit of the row is 0, flip the row
            if(grid[i][0] == 0) {
                flipRow(grid[i]);
            }
        }

        // 2. Flip columns if necessary
        for(int j = 1; j < ncols; j++) { // Start from the second column
            int countOnes = 0;
            for(int i = 0; i < nrows; i++) {
                // Count the number of 1s in the column
                countOnes += grid[i][j];
            }
            // If the number of 1s is less than half of the rows, flip the column
            if(countOnes*2 < nrows) {
                flipColumn(grid, j);
            }
        }

        // 3. Calculate the final score
        int score = 0;
        for(int i = 0; i < nrows; i++) {
            int rowVal = 0;
            for(int j = 0; j < ncols; j++) {
                // Convert binary to decimal
                rowVal = rowVal * 2 + grid[i][j];
            }
            score += rowVal;
        }
        return score;
    }
    
private:
    // Function to flip a row
    void flipRow(vector<int>& row) {
        for(int& cell : row) {
            // Flip each cell
            cell = (cell == 0) ? 1 : 0;
        }
    }

    // Function to flip a column
    void flipColumn(vector<vector<int>>& grid, int colIdx) {
        for(int i = 0; i < grid.size(); i++) {
            // Flip the cell in the specified column
            grid[i][colIdx] = (grid[i][colIdx] == 0) ? 1 : 0;
        }
    }
};
