class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int n=arr.size(), left=0, right=n-1;
        int sum=0, prefixSum=0;
        for(int i: arr){
            sum += i;
        }
        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            if(prefixSum == sum-prefixSum)
                return true;
            if(prefixSum > sum-prefixSum)//not possible to split equally
                break;
        }
        return false;
    }
};