class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        //find the minimum and the maximum between all the m arrays
        int mini=1e5, maxi=-1e5, m=arrays.size(), dist=0;
        for(int i=0; i<m; i++){
            dist = max({dist, maxi - arrays[i][0], arrays[i].back() - mini});
            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }
        return dist;
    }
};