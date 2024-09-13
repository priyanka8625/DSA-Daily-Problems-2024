class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size(), prefix=0;
        //preprocessing prefix xor
        vector<int> prefix_xor(n, 0);
        for(int i=0; i<n; i++){
            prefix ^= arr[i];
            prefix_xor[i] = prefix;
        }
        //compute xor of each query using : prefix[right]-prefix[left-1] except when left=0
        for(auto query : queries){
            int query_result = 0;
            if(query[0]==0)
                query_result = prefix_xor[query[1]];
            else
                query_result = prefix_xor[query[1]] ^ prefix_xor[query[0]-1];
            ans.push_back(query_result);
        }
        return ans;
    }
};