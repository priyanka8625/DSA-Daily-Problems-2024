class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows=matrix.size(), cols=matrix[0].size();
        for(int i=0; i<rows; i++){
            int minInRow = INT_MAX, colIndex;
            for(int j=0; j<cols; j++){
                if(minInRow > matrix[i][j]){
                    minInRow = matrix[i][j];
                    colIndex = j;
                } 
            }
            //check if it is max in it's column 
            bool is_Lucky=1;
            for(int j=0; j<rows; j++){
                if(matrix[j][colIndex] > minInRow){
                    is_Lucky = 0;
                    break;
                }
            }
            if(is_Lucky){
                ans.push_back(minInRow);
            }
        }
        return ans;
    }
};