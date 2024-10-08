class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201, 0);
        int n = nums.size();
        for(int i : nums){
            freq[i+100]++;
        }
        sort(nums.begin(), nums.end(), [&](int &a, int &b){
            if(freq[a+100]==freq[b+100]){
                return a>b;
            }
            return freq[a+100]<freq[b+100];
        });
        return nums;
    }
};