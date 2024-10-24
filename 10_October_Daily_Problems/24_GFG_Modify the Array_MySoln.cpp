class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size(), index=0;
        vector<int> ans(n, 0);
        
        for(int i=0; i<n-1; i++){
            if(arr[i]>0){
                if(arr[i+1]>0 && arr[i]==arr[i+1]){//if curr and next both are valid
                    ans[index] = arr[i]+arr[i];
                    arr[i+1] = 0;
                    index++;
                }else{
                    ans[index] = arr[i];//put as it is
                    index++;
                }
            }
        }  
        if(arr[n-2]!=arr[n-1]){
            ans[index] = arr[n-1];
        }
        return ans;
    }
};