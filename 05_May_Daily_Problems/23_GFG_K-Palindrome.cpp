class Solution{
public:
    int dp[1001][1001];
   int solve(string &str,int i,int j){
       if(i>=j) return 0;
       int &ans= dp[i][j];
       if(ans!=-1) return ans;
       
       if(str[i]== str[j]){
           return solve(str,i+1,j-1); //no deletion needed
       }
        return  (ans=  1+  min(solve(str,i+1,j) , solve(str,i,j-1)) );
       }
    int kPalindrome(string str, int n, int k)
    {
        // code here
      memset(dp,-1,sizeof(dp));
      int op=  solve(str,0,n-1);
      if(op<=k) return true;
      return false;
    }
};