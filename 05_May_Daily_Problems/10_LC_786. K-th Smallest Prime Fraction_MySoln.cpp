class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans(2);
        int n = arr.size();
        //create a max heap to store the prime fraction of the two prime numbers
        priority_queue<pair<double, pair<int, int>>> pq;

        //insert first all n*n prime fractions into maxheap
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                //insert current fraction
                double fraction = (double)arr[i]/arr[j];
                pq.push(make_pair(fraction, make_pair(arr[i], arr[j])));

                //maintain k smallest elements in the maxheap
                if(pq.size()>k){
                    pq.pop();//pop out the largest element from queue
                }
            }
        }
        
        ans[0] = pq.top().second.first;
        ans[1] = pq.top().second.second;
        return ans;
    }
};