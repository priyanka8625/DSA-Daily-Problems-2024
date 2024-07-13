class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left=0, right=n-1;
        while(left<right){
            while(left<right && arr[left]==0){
                left++;
            }
            while(left<right && arr[right]==1){
                right--;
            }
            if(left<right){
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};