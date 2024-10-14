class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<long long> pq(nums.begin(), nums.end());
        while(!pq.empty() && k){
            int curr = pq.top();
            pq.pop();
            score += curr;
            curr = ceil((double)curr/3);
            pq.push(curr);
            k--;
        }
        return score;
    }
};