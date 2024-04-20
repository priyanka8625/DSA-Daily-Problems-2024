class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int m=land.size(), n=land[0].size();
        int  bottom, right;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check if (i, j) is the start of a new group
                if(land[i][j] == 1 && (i==0 || land[i-1][j]==0) and (j==0 || land[i][j-1]==0)){
                    bottom = i;
                    right = j;

                    //expand the group to find bottom row
                    while(bottom+1 < m && land[bottom+1][j]==1)
                        bottom++;
                    //expand the group to find right row
                    while(right+1<n && land[i][right+1]==1)
                        right++;
                    //insert the group boundaries
                    ans.push_back({i, j, bottom, right});
                }
            }
        }
        return ans;
    }
};