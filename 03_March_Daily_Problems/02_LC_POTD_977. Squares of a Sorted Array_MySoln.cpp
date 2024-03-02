class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int left=0, right=n-1;
        //we'll compare the elements at ending as we can't assure that the largest elements are present at the end of the array
        //in terms of absolute value
        int index = n-1;
        while(left <= right){
            if(abs(nums[left])>=abs(nums[right])){
                ans[index] = nums[left]*nums[left];
                left++;
            }else{
                ans[index] = nums[right]*nums[right];
                right--;
            }    
            index--;
        }
        return ans;
    }
};