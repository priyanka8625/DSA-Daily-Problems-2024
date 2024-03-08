class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> freq;
        int n = nums.size(), maxFreq = INT_MIN, noOfElements=0;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }
        for(auto& [key,value] : freq)
            if(value == maxFreq)
                noOfElements+=value;//no of elements will be the frequency of the numbers matching maxFreq
        return noOfElements;
    }
};