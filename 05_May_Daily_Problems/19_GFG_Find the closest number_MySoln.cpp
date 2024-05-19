class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        //apply binary search 
        int left=0, right=n-1, diff=INT_MAX, ans=0, currDiff=0;
        while(left <= right){
            int mid = left + (right-left)/2;
            currDiff = abs(arr[mid]-k);
            //1. update ans
            //if current diff is < the diff obtained so far
            if(currDiff < diff){
                ans = arr[mid];
                diff = currDiff;
            }else if(currDiff == diff)
                ans = max(ans, arr[mid]);
            
            //2. update pointers
            if(arr[mid] == k){
                return arr[mid];
            }else if(arr[mid] < k){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    } 
};