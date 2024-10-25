class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int index=0, n=arr.size();
        //descending at even and ascending at odd indices
        vector<int> ans(n, 0);
        sort(arr.begin(), arr.end());
        int start=0, end=n-1;
        while(index<n){
            if(index&1){
                ans[index++] = arr[start++];
            }else{
                ans[index++] = arr[end--];
            }
        }
        return ans;
    }
};