class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        //we'll use binary search to find the peak element in the array
        int n=a.size(),left=0, right=n-1;
        int mid=0;
        //continue search untill left == right
        while(left<right){
            mid = left + (right-left)/2;
            
            //as the array can only be strictly increasing and then decreasing
            //we can always compare the mid'th ele with it's next element
            //if mid > mid+1 it means that we are on the decreasing slope and peak can be at left half  
            // including mid'th one
            if(a[mid] > a[mid+1]){
                right = mid;
            }else if(a[mid] < a[mid+1]){
                //we're on the increasing slope and we need to move to the right half of mountain
                //to find peak, but the peak can't be mid so left will be mid+1
                left = mid+1;
            }
        }
        //left and right are now pointing to the peak element
        return a[left];
    }
};