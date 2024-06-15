class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //store pairs of <capital, profit> an sort them in ascending order 
        vector<pair<int, int>> pairs;
        int n = profits.size();
        for(int i=0; i<n; i++){
            pairs.push_back({capital[i], profits[i]});
        }
        sort(pairs.begin(), pairs.end());
        priority_queue<int> pq;
        int i=0;

        while(k--){
            //get all the profits having capital <= w
            while(i<n && pairs[i].first<=w){
                pq.push(pairs[i].second);
                i++;
            }
            if(pq.empty())//if all projects are finished
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};