class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)//array is empty
            return 0;
        
        int n = nums.size();
        vector<int> dp(n, 1);//create a dp array of n size initialized with all 1s

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());//returns an iterator so use * to print the value

    }
};
