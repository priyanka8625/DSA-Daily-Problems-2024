class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minheap;
        unordered_set<long> vis;
        vector<int> prime_factors = {2, 3, 5};
        minheap.push(1);
        vis.insert(1);
        long curr_number = 0;
        for(int i=0; i<n; i++){
            curr_number = minheap.top();
            minheap.pop();
            for(long primes : prime_factors){
                long new_prime = curr_number * primes;
                if(vis.count(new_prime) == 0){
                    minheap.push(new_prime);
                    vis.insert(new_prime);
                }
            }
        }
        return (int)curr_number;
    }
};