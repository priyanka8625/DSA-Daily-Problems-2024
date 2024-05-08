class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> answer(n);
        //store the pairs of score and their index into maxheap
        priority_queue<pair<int, int>> pq;

        for(int i=0; i<n; i++){
            pq.push(make_pair(score[i], i));
        }
        //keep track of the first 3 highest values to assign them ranks
        int rank=1;
        while(!pq.empty()){
            //take the highest score
            pair<int, int> highest = pq.top();
            pq.pop();
            
            int index = highest.second;
            if(rank==1)
                answer[index] = "Gold Medal";
            else if(rank==2)
                answer[index] = "Silver Medal";
            else if(rank==3)
                answer[index] = "Bronze Medal";
            else//place other ranks equal to their rank no
                answer[index] = to_string(rank);
            rank++;
        }
        return answer;
    }
};