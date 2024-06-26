
class Solution {
    int row[4]={0, 0, -1, 1};
    int col[4]={-1, 1, 0, 0};
    int n, m;
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        n = matrix.size(), m=matrix[0].size();
        int count=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    for(int k=0; k<4; k++){
                        if(isValid(i+row[k], j+col[k]) && matrix[i+row[k]][j+col[k]]==1)
                            count++;
                    }
                }
            }
        }
        return count;
    }
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
};