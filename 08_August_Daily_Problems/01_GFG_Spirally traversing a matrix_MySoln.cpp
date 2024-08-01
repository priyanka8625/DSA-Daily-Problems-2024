class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int> ans;
        int n=matrix.size(), m=matrix[0].size(), top=0, bottom=n-1, left=0, right=m-1;
        while(left<=right && top<=bottom){
            //top
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            //right
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                //bottom
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right){
                //left
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};