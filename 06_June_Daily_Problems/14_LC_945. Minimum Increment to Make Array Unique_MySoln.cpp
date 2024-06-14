class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves=0;
        //sort array so that we get duplicates at consecutive positions
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            //if we find any duplicates or the currVal < prevVal due to prev iterations of for loop
            if(nums[i] <= nums[i-1]){
                //moves will be equal to the diff between prevele+1 and curr ele
                moves += (nums[i-1]+1) - nums[i];
                //update the curr ele by prevele+1
                nums[i] = nums[i-1]+1;//this step can lead to duplicates or change in sorted order
                //but at the end array will be updated such that all eles are unqiue 
            }
        }
        return moves;
    }
};