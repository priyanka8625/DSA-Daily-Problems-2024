class Solution {
private:
    unordered_map<int, int> subset;
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return getBeautifulSubsets(nums, k, 0);
    }
    int getBeautifulSubsets(vector<int>& nums, int &k, int index){
        if(index == nums.size()){
            if(subset.size() != 0)
                return 1;
            return 0;
        }
        int left=0, right=0;
        //not include current index
        left = getBeautifulSubsets(nums, k, index+1);
        //include current index if current element's diff is != k for all eles included in subset
        //which can be checked using num-k and num+k is not in map
        //because |num-x| = k=> x=k-/+num, if x is there in subset then dont include current index 
        if(subset[nums[index]-k] == 0 && subset[nums[index]+k] == 0){
            //include index
            subset[nums[index]]++;
            right = getBeautifulSubsets(nums, k, index+1);
            subset[nums[index]]--;//backtrack
        }
        return left + right;
    }
};