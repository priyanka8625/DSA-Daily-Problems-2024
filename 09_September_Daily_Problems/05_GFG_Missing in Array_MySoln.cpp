class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        // Your code goes here
        int exp_sum = n*(n+1)/2;
        int actual_sum = 0;
        for(int ele : arr)
            actual_sum += ele;
        return exp_sum - actual_sum;
    }
};