class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum = (sum + nums[j])%mod;
                subarraySums.push_back(sum);
            }
        }
        sort(subarraySums.begin(), subarraySums.end());
        int ans=0;
        for(int i=left-1; i<right; i++){
            ans = (ans + subarraySums[i])%mod;
        }
        return ans;
    }
};