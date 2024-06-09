class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefixSum=0, remainder, total=0;
        for(int i=0; i<nums.size(); i++){
            //get prefixSum
            prefixSum += nums[i];
            //get the remainder for current prefixSum
            remainder = prefixSum % k;

            if(remainder < 0)
                remainder = remainder + k;
            
            if(mp[remainder]){
                total += mp[remainder];
            }
            mp[remainder]++;
        }
        return total;
    }
};