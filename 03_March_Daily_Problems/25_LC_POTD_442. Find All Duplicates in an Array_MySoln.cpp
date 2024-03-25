class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int index = abs(nums[i]) - 1;//this will give the index of the elements between 1 to n 8->7, 7->6..1->0
            if(nums[index]<0)//it's been visited previously
                ans.push_back(abs(nums[i]));//the positive element
            else//visit the index of current element by making it negative
                nums[index] = -nums[index];
        }
        return ans;
    }
};