class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int majorElement=0, majorCount=INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++)
            freq[nums[i]]++;
        for(auto& [key,value] : freq)
            if(majorCount < value){
                majorCount = value;
                majorElement = key;
            }
        return majorElement;
    }
};