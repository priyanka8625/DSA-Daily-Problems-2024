class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int max_sum = INT_MIN, sum=0;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            max_sum = max(max_sum, sum);
            if(sum<0){
                sum = 0;
            }
        }
        return max_sum;
    }
};