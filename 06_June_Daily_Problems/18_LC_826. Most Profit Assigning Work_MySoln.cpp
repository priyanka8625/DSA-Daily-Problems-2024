class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> pairs;
        int n=difficulty.size(), m=worker.size();
        for(int i=0; i<n; i++){
            pairs.push_back({difficulty[i], profit[i]});
        }
        sort(pairs.begin(), pairs.end());
        sort(worker.begin(), worker.end());
        int total=0, maxProfit=0, difIndex=0;
        for(int i=0; i<m; i++){
            while(difIndex<n){
                //check if curr difficulty <= worker[i]
                if(pairs[difIndex].first<=worker[i]){
                    //take max profit accordingly
                    maxProfit = max(maxProfit, pairs[difIndex].second);
                }else{
                    break;
                }
                difIndex++;
            }
            //add maxProfit into total
            total += maxProfit;
        }
        return total;
    }
};