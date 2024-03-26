class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1, i=0, prevElement=0;
        //reach out to the first positive number
        while(i<nums.size() && nums[i] <= 0)
            i++;

        for(; i<nums.size(); i++){
            if(prevElement == nums[i])
                continue;
            if(count != nums[i])
                return count;
            prevElement = nums[i];
            count++;
        }
        return count;
    }
};