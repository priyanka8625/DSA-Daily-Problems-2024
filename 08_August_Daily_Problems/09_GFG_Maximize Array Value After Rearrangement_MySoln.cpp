
class Solution {
    long MOD = 1e9+7;
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function
        sort(arr.begin(), arr.end());
        long sum=0;
        for(int i=0; i<arr.size(); i++){
            sum = (sum + (arr[i]%MOD * i)%MOD)%MOD;
        }
        return sum;
    }
};