class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lossCountOfLoosers;
        set<int> loosers, winners;
        vector<vector<int>> ans;
        int n = matches.size();
        for(int i=0; i<n; i++){
            // find count of each looseri
            lossCountOfLoosers[matches[i][1]]++;
        }
        //now find all the winners which didn't lost any matches
        //which means the 0th element which doesn't exists in map will be the winner at ans[0]
        // and if the an element in map occurs exactly once, it means push it into ans[1]
        for(int i=0; i<n; i++){
            if(lossCountOfLoosers.find(matches[i][0]) == lossCountOfLoosers.end()){
                // if not found 
                winners.insert(matches[i][0]);
            }
        }
        //check exact one occurance of looseri i.e. any element that has count 1 in map
        for(auto& [key, value] : lossCountOfLoosers){
            if(value==1){
                loosers.insert(key);
            }
        }

        vector<int> win(winners.begin(), winners.end());
        vector<int> lose(loosers.begin(), loosers.end());
        ans.push_back(win);
        ans.push_back(lose);
        return ans;
    }
};