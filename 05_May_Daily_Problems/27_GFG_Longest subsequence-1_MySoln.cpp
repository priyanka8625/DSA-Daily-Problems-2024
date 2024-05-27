class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<int> temp;
        return getSubseq(n, a, -1, 0, 0);
    }
    int getSubseq(int n, vector<int>& a, int prev, int index, int length){
        if(index == n){
            return length;
        }
        int ans=0;
        //not include curr ele 
        ans = max(ans, getSubseq(n, a, prev, index+1, length));
        //include curr ele only if the diff with prev is 1 and prev is not -1
        if(prev==-1 || abs(prev-a[index])==1){
            ans = max(ans, getSubseq(n, a, a[index], index+1, length+1));
        }
        return ans;
    }
};