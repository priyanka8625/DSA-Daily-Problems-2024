class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX, currSum=0, n=arr.size();
        for(int i=0; i<n; i++){
            int start=i+1, end=n-1;
            while(start<end){
                int sum = arr[start]+arr[end]+arr[i];
                if(sum ==target){
                    return target;
                }else if(sum < target){
                    start++;
                }else{
                    end--;
                }
                
                //update min diff got so far 
                if(minDiff > abs(target-sum)){
                    minDiff = abs(target-sum);
                    currSum = sum;
                }else if(minDiff == abs(target-sum)){
                    currSum = max(sum, currSum);
                }
            }
        }
        return currSum;
    }
};