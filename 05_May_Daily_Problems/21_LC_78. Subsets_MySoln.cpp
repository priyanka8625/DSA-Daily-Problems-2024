class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //let's use recursion for calculating the subsets 
        vector<vector<int>> ans;
        vector<int> temp;
        getSubsets(nums, 0, temp, ans);
        return ans;
    }
    void getSubsets(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& ans){
        //base case
        if(index == nums.size()){
            //append the subset into ans
            ans.push_back(temp);
            return;
        }

        //not include the current index
        getSubsets(nums, index+1, temp, ans);
        //include current index
        temp.push_back(nums[index]);
        getSubsets(nums, index+1, temp, ans);
        temp.pop_back();
    }
};