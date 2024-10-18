class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int ele : nums){
            maxOR |= ele;
        }

        //now find subsets with max OR
        int count=0;
        findSubsets(nums, 0, 0, maxOR, count);
        return count;
    }
    void findSubsets(vector<int> &nums, int index, int OR, int maxOR, int &count){
        if(index == nums.size()){
            if(OR == maxOR)
                count++;
            return;
        }
        //for each ele, we have choices: 1. take or 2. not take
        findSubsets(nums, index+1, OR, maxOR, count);
        findSubsets(nums, index+1, OR|nums[index], maxOR, count);
    }
};