class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        k = k%m;
        if(k == 0) return mat;
        
        reverse(0, k-1, n, mat);
        reverse(k, m-1, n, mat);
        reverse(0, m-1, n, mat);
        return mat;
    }
    void reverse(int low, int high, int n, vector<vector<int>> &mat){
        while(low<high){
            //reverse rows
            for(int i=0; i<n; i++)
                swap(mat[i][low], mat[i][high]);
            
            low++;
            high--;
        }
    }
};