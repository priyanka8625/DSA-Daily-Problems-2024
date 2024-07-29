class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int ans=-1;
        int rows=arr.size(), cols=arr[0].size();
        int r=0, c=cols-1;
        // start from top right corner 
        // if encountered1 then move o left
        // if 0 move down 
        while(r<rows && c>=0){
            if(arr[r][c] == 1){
                c--;
                ans = r;
            }else{
                r++;
            }
        }
        return ans;
    }
};