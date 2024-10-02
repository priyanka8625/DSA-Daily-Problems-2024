
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());

        for(int i=0; i<n; i++){
            if(mp.find(arr[i]) != mp.end())
                continue;
            mp[arr[i]] = mp.size()+1;
        }

        for(int i=0; i<n; i++){
            ans[i] = mp[ans[i]];
        }
        return ans;
    }
};