class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        int n = arr.size();
        if(n<3)
            return false;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            int start=0, end=n-1;
            while(start<end){
                if(start==i){
                    start++;
                    continue;
                }
                if(end == i){
                    end--;
                    continue;
                }
                if(arr[start]+arr[end] == arr[i]){
                    return true;
                }else if(arr[start]+arr[end] < arr[i]){
                    start++;
                }else{
                    end--;
                }
            }
        }
        return false;
    }
};