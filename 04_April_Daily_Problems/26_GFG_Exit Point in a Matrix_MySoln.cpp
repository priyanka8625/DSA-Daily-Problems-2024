class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        string dir = "R";//by default we move to right direction
        int row=0, col=0;
        vector<int> ans;
        while(row<n && row>=0 && col<m && col>=0){
            if(dir == "R"){
                if(matrix[row][col]==1){
                    dir = "D";
                    matrix[row][col] = 0;
                    row++;//move down
                }
                //if not 1 then continue in the same direction
                else{
                    col++;
                }
            }else if(dir=="D"){
                if(matrix[row][col]==1){
                    dir = "L";
                    matrix[row][col] = 0;
                    col--;//move left
                }else{
                    row++;
                }
            }else if(dir=="L"){
                if(matrix[row][col]==1){
                    dir = "U";
                    matrix[row][col] = 0;
                    row--;//move up
                }else{
                    col--;
                }
            }else if(dir == "U"){
                if(matrix[row][col]==1){
                    dir = "R";
                    matrix[row][col] = 0;
                    col++;//move right
                }else{
                    row--;
                }
            }
        }
        if(row<0)
            return {0, col};
        if(row==n)
            return {row-1, col};
        if(col<0)
            return {row, 0};
        if(col==m)
            return {row, col-1};
    }
};