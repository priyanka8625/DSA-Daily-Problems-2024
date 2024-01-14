class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int>ans;
        map<vector<int>, int>mpp;
        for(int i=0; i<M; i++){
            // insert ith row into mpp if it is not already present
            if(mpp.find(matrix[i])==mpp.end()){
                mpp[matrix[i]]++;
            }else{
                // if ith row is already present in mpp, it means that current row is 
                // duplicate of some previous row, so push the ith index into vector
                ans.push_back(i);
            }
        }
        return ans;
    } 
};