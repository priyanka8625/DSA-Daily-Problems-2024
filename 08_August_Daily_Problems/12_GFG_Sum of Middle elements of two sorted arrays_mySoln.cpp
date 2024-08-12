 class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        int n = arr1.size(), index=0, i=0, j=0;
        vector<int> ans(n+n);
        while(i<n && j<n){
            if(arr1[i]<arr2[j]){
                ans[index++] = arr1[i++];
            }else{
                ans[index++] = arr2[j++];
            }
        }
        while(i<n){
            ans[index++] = arr1[i++];
        }
        while(j<n){
            ans[index++] = arr2[j++];
        }
        int start=0, end=n+n-1,mid = start+(end-start)/2;
        return ans[mid]+ans[mid+1];
    }
};
