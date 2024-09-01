class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n < original.size() || m*n > original.size())
            return {};
        
        int size = original.size(), index=0;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i=0; i<m && index<size; i++){
            for(int j=0; j<n && index<size; j++){
                ans[i][j] = original[index];
                index++;
            }
        }
        return ans;
    }
};