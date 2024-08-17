
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        // code here
        int n = nums.size();
        vector<long long int> ans(n, 1);
        long long int product = 1;
        //store the product of 0->i-1 at i'th loc
        for(int i=0; i<n; i++){
            ans[i] = product;
            product *= nums[i];
        }
        //store n-1->i+1 product at i'th loc
        product = 1;
        for(int i=n-1; i>=0; i--){
            ans[i] *= product;
            product *= nums[i];
        }
        return ans;
    }
};