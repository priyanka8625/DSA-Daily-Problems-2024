class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        vector<int> ans(q, 0);
        
        sort(b.begin(), b.end());
        
        for(int i=0; i<q; i++){
            int ele = a[query[i]];
            int start=0, end=n-1, mid;
            while(start<=end){
                mid = start + (end-start)/2;
                if(b[mid]<=ele){
                    ans[i] = mid+1;
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            }
        }
        return ans;
    }
};