class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winCount, looseCount;
        vector<vector<int>> ans;
        int n = matches.size();
        for(int i=0; i<n; i++){
            // find count of each looseri and winneri
            winCount[matches[i][0]]++;
            looseCount[matches[i][1]]++;
        }
        //now find all the loosers, means the ones whoose count in looseCount is 1
        //and winners will be the ones whose count in winCount is >=1 and they are not present in looseCount mean didn't loose any matches
        vector<int> loosers, winners;

        //find loosers first
        for(auto& [key, value]: looseCount){
            if(value == 1){
                loosers.push_back(key);
            }
        }
        //now find winners
        for(auto& [key, value] : winCount){
            if(value>=1 && looseCount.find(key)==looseCount.end()){
                winners.push_back(key);
            }
        }
        //sort both the vectors
        sort(winners.begin(), winners.end());
        sort(loosers.begin(), loosers.end());
        ans.push_back(winners);
        ans.push_back(loosers);
        return ans;
    }
};