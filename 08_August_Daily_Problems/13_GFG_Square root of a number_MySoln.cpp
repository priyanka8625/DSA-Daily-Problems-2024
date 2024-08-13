class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        long long start=1, end=n, mid, ans=-1;
        while(start<=end){
            mid = start+(end-start)/2;
            if(mid*mid == n){
                return mid;
            }else if(mid*mid < n){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};
