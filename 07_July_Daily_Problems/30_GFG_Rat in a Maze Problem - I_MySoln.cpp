class Solution {
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};
    int n;
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        if(mat[0][0]==0)
            return {};
        vector<string> ans;
        string temp="";
        n=mat.size();
        findPaths(mat, 0, 0, temp, ans);
        return ans;
    }
    void findPaths(vector<vector<int>>& mat, int i, int j, string& temp, vector<string>& ans){
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        
        mat[i][j] = 0;//mark visited
        
        //check neighbours
        for(int k=0; k<4; k++){
            int newI=i+row[k], newJ=j+col[k];
            if(isValid(newI, newJ) && mat[newI][newJ]==1){
                temp.push_back(dir[k]);
                findPaths(mat, newI, newJ, temp, ans);
                temp.pop_back();
            }
        }
        
        mat[i][j] = 1;
    }
    bool isValid(int i, int j){
        return i>=0 && i<n && j>=0 && j<n;
    }
};