class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n<3 || m<3)
            return -1;
            
        int ans=INT_MIN, sum=0;
        for(int row=0; row<n-2; row++){
            for(int col=0; col<m-2; col++){
                sum = mat[row][col]+mat[row][col+1]+mat[row][col+2]
                        + mat[row+1][col+1]
                        + mat[row+2][col]+mat[row+2][col+1]+mat[row+2][col+2];
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};