class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //NOTE: the bitwise AND of any two different numbers will always be strictly less than 
        //the maximum of the two numbers
        //1. so first find the maximum element of the array nums
        //2. find the length of the subarray which contains all max elements, this is our ans

        int maxLength=0, maxEle=INT_MIN, n=nums.size();
        for(int i:nums){
            maxEle = max(maxEle, i);
        }
        for(int i=0; i<n; i++){
            int length = 0;
            while(i<n && maxEle==nums[i]){
                length++;
                i++;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};