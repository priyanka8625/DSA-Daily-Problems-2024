class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // exactly k nice subarrays = (atmost k nice subarrays) - (atmost k subarrays)
        return atmost(nums, k) - atmost(nums, k-1);
    }
    int atmost(vector<int>& nums, int k){
        int n = nums.size(), start=0, end=0, count=0, subarrays=0;
        while(end<n){
            if(nums[end]&1)
                count++;
            //shrink window if odd number count exceeds atmost k condn
            while(count > k){
                if(nums[start]&1)
                    count--;
                start++;
            }
            //get the number of subarrays that can be formed within start and end 
            subarrays += (end-start+1);
            end++;
        }
        return subarrays;
    }
};