class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;
        for(int i: arr1)
            freq[i]++;
        vector<int> ans;
        //place arr2 first
        for(int i : arr2){
            while(freq[i]){
                ans.push_back(i);
                freq[i]--;
            }
        }
        for(auto [key, value] : freq){
            while(value){
                ans.push_back(key);
                value--;
            }
        }
        return ans;
    }
};