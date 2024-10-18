class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int ans=0;
        for(int ele : arr){
            ans ^= ele;
        }
        return ans;
    }
};