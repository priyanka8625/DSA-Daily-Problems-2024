class Solution
{   
    public:
    bool compare(vector<int> &mat1, vector<int> &mat2, int &n){
        for(int i=0; i<n; i++){
            if(mat1[i] != mat2[i])
                return false;
        }
        return true;
    }
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // code here
        set<int> duplicateRows;
        
        //loop through each row of matrix
        for(int i=0; i<M-1; i++){
            //start comparing ith row with i+1 to n-1 rows
            for(int j=i+1; j<M; j++){
                if(compare(matrix[i], matrix[j], N))
                    duplicateRows.insert(j);
            }
        }
        
        vector<int> ans(duplicateRows.begin(), duplicateRows.end());
        return ans;
    } 
};