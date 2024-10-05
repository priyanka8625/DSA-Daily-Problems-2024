class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        int res = 1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]<=res){
                //we can form all subsets having sums from 1 to res
                res += arr[i];
            }else{
                return res;
            }
        }
        return res;
    }
};