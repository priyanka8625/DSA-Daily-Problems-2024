class Solution
{
    int mod = 1e9+7;
    int solve(int i,int j,int n,int m,string s,string t,
            vector<vector<int>> &dp){
        if(j>=m){
            return 1;
        }
        if(i>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i]==t[j]){
            ans = (solve(i+1,j+1,n,m,s,t,dp) + 
            solve(i+1,j,n,m,s,t,dp))%mod;
        }
        else{
            ans = solve(i+1,j,n,m,s,t,dp);
        }
        return dp[i][j] = ans;
    }
    public:
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n = s.length();
      int m = t.length();
      vector<vector<int>> dp(n,vector<int>(m,-1));
      return solve(0,0,n,m,s,t,dp);
    }
};