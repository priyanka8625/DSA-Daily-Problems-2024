class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        //let's apply binary search to find a pair such that abs(pairDiff) == x
        sort(arr.begin(), arr.end());
        
        //check for each element if there exists an element which makes a valid pair
        for(int i=0; i<n; i++){
            int left =i+1, right=n-1, mid=0;
            int exp = arr[i]+x; //search for the expected value whose difference with arr[i] == x
            while(left <= right){
                mid = left + (right-left)/2;
                if(arr[mid] == exp)
                    return 1;
                else if(arr[mid] < exp)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        
        return -1;
    }
};