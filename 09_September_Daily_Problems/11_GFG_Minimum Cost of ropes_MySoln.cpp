class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        long long cost=0;
        long long n = arr.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        
        while(pq.size()>1){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            cost += first+second;
            
            pq.push(first+second);
        }
        return cost;
    }
};