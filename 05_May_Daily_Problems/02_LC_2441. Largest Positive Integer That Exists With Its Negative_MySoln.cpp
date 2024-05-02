class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int ans=-1;

        //now iterate through nums and check if for any no there's a opposite sign no present in set
        for(int i:nums){
            if(i>ans && numsSet.find(-i)!=numsSet.end()){
                ans = i;
            }
        }
        return ans;
    }
};