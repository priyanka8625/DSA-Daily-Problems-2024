class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> freq;
        for(int ele : arr){
            freq[ele]++;
        }
        int count =0;
        for(int ele : arr){
            if(freq.find((ele - k)) != freq.end()){
                count += freq[(ele-k)];
            }
        }
        return count;
    }
};