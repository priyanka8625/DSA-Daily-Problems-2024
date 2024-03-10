class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq;
        vector<int> uniqueVals;
        for(int i:nums1){
            freq[i]++;
        }
        //now check if the elements in nums2 are also present in map 
        for(int i:nums2){
            if(freq[i]){//if the value isn't 0
                uniqueVals.push_back(i);
                freq.erase(i);
            }
        }
        return uniqueVals;
    }
};