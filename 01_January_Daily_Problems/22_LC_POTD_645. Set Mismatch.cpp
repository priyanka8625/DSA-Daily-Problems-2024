class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size(), sum=0;
        int originalSum = n*(n+1)/2;
        vector<int> ans(2);
        sort(nums.begin(), nums.end());
        int i=0;
        for(i=0; i<n-1; i++){
            //if repeatition occurs add it to ans and continue 
            if(nums[i]==nums[i+1]){
                //repeating element 
                ans[0] = nums[i];
                continue;
            }
            //add all the elements without repetition
            sum += nums[i];
        }
        //add last element to sum
        sum += nums[i];
        //missing element
        ans[1] = originalSum - sum;
        return ans;
    }
};