class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, int>> heightIndex;
        int n = heights.size();
        for(int i=0; i<n; i++){
            heightIndex.push_back({heights[i], i});
        }
        sort(heightIndex.begin(), heightIndex.end(), [&](pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        });
        vector<string> ans(n);
        for(int i=0; i<n; i++){
            ans[i] = names[heightIndex[i].second];
        }
        return ans;
    }
};