class Solution
{
public:
    int dp[505][505];
    int mod=1e9+7;
    int fn(int x,int y){
       if(x==0&&y==0)return 1;
       if(dp[x][y]!=-1)return dp[x][y];
       int ans=0;
       if(x>0)ans+=fn(x-1,y)%mod;
       if(y>0)ans+=fn(x,y-1)%mod;
       return dp[x][y]=ans%mod;
    }
    int ways(int x, int y)
    {
        memset(dp,-1,sizeof(dp));
        return fn(x,y);
    }
};