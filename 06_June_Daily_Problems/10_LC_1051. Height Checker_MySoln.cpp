class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        sort(expected.begin(), expected.end());
        int n = heights.size(), count=0;
        for(int i=0; i<n; i++){
            if(heights[i] != expected[i])
                count++;
        }
        return count;
    }
};