class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //from the given problem statement and examples
        //we can come to three cases, dependng on the no. of zeros in the arrays
        //if zeros==0, then each index will comntain totalProduct/nums[i]
        //if zeros==1, then all nonzero eles will be 0 and zero element will contain totalProduct without including zero
        //if zeros>=2, then all the indices in ans will be zero only
        //so, first we'll count the no. of zeros
        int n = nums.size();
        vector<int> ans(n, 0);
        int product = 1;
        int zeros = 0;
        
        for (int num : nums) {
            if (num == 0) {
                zeros++;
                continue;
            }
            product *= num;
        }

        if (zeros == 1) {
            for (int i = 0; i < n; i++) {
                ans[i] = nums[i] == 0 ? product : 0;
            }
        } else if (zeros == 0) {
            for (int i = 0; i < n; i++) {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};
