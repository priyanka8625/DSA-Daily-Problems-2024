class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        //get the freq of each x in arr as x%k so that we can compare the extra units of any two 
        //elements to make the whole number whose sum is == k and it will be divisible by k
        //to avoid -ve value effect on %k operation add each value by k and then do %k 
        vector<int> freq(k,0);
        for(int x : arr){
            int rem = x%k;
            if(rem < 0){
                rem += k;
            }
            freq[rem%k]++;
        }
        if(freq[0]%2 != 0)
            return false;

        for(int i=1; i<=k/2; i++){
            if(freq[i] != freq[k-i]){
                return false;
            }
        }
        return true;
    }
};