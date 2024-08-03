class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size(), m=mat[0].size();
        int ans=-1;
        //find all 0 row - the one who doesn't know anyone
        for(int i=0; i<n; i++){
            int knowsCount=0;
            for(int j=0; j<n; j++){
                if(mat[i][j]==1)
                    knowsCount++;
            }
            if(knowsCount==0 && ans==-1){
                ans = i;
            }else if(knowsCount==0 && ans!=-1){//there can not be more than one celebrities
                return -1;
            }
        }
        if(ans==-1)
            return ans;
        
        //check if everyone knows i'th person except the i'th person itself
        for(int i=0; i<n; i++){
            if(i!=ans && mat[i][ans]!=1)
                return -1;
        }
        
        return ans;
    }
};