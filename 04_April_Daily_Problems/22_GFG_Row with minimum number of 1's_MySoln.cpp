class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        // code here
        int rowNumber=0, min1s=INT_MAX;
        for(int i=0; i<n; i++){
            int current1s=0;
            for(int j=0; j<m; j++){
                //count no. of ones in current row
                current1s += (a[i][j]==1);
            }
            if(current1s < min1s){
                min1s = current1s;
                rowNumber = i+1;
            }
        }
        return rowNumber;
    }
};