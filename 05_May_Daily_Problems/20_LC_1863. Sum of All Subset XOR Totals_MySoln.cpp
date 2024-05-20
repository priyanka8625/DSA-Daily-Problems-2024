class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xorSum=0;
        getXORSum(nums, 0, 0, xorSum);
        return xorSum;
    }
    void getXORSum(vector<int>& nums, int index, int sum, int &xorSum){
        if(index == nums.size()){
            xorSum += sum;
            return;
        }
        //not include current index
        getXORSum(nums, index+1, sum, xorSum);
        //include curren index in xorSum
        getXORSum(nums, index+1, sum^nums[index], xorSum); 
    }
};