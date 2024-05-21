class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        //max heap
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-x);
            //store -ve of diff
            if(diff!=0) pq.push(make_pair(-diff,arr[i]));
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};