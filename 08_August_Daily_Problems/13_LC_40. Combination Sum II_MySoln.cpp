class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        getCombinations(candidates, temp, ans, target, 0);

        return ans;
    }
    void getCombinations(vector<int>& candidates, vector<int>& temp, vector<vector<int>>& ans, int target, int index){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            //avoid duplicate entries at same index
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            getCombinations(candidates, temp, ans, target-candidates[i], i+1);
            temp.pop_back();
        }
    }
};