class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& a) {
        int mod =1e9 +7;
        int sum = accumulate(a.begin(), a.end(), 0);
        if ((sum + d) % 2 != 0) {
            return 0;
        }
        int target = (sum + d) / 2;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= a[i]; j--) {
                dp[j] = (dp[j] + dp[j - a[i]]) %mod;
            }
        }
        return dp[target];
    }
};