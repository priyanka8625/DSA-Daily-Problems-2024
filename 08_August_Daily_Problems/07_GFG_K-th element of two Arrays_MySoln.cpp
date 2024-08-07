class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n=arr1.size(), m=arr2.size(), i=0, j=0, ans=-1, index=0;
        while(i<n && j<m && index!=k){
            if(arr1[i]<=arr2[j]){
                ans = arr1[i];
                i++;
            }else{
                ans = arr2[j];
                j++;
            }
            index++;
        }
        while(index!=k && i<n){
            ans = arr1[i];
            i++;
            index++;
        }
        while(index!=k && j<m){
            ans = arr2[j];
            j++;
            index++;
        }
        return ans;
    }
};