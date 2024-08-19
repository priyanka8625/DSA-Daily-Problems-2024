class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        int n = arr.size();
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        for(int i=k; i<n; i++){
            pq.push(arr[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};