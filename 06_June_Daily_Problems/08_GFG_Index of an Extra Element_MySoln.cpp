class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int left=0, right=n-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(arr1[mid] == arr2[mid])
                left = mid + 1;
            else if(mid > n-2 || arr1[mid] != arr2[mid])//if mid goes beyong arr2's length
                right = mid;
        }
        return left;
    }
};