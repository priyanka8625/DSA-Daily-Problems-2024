class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        //convert the first 3 largest numbers to smallest number
        sort(nums.begin(), nums.end());
        int n=nums.size(), largest=nums[n-1], smallest=nums[0];
        int minDiff=largest-smallest;
        for(int i=0; i<=3; i++){
            minDiff = min(minDiff, nums[n-(3-i+1)]-nums[i]);
        }
        return minDiff;
    }
};