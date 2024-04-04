class Solution
{
    public:
    int mod = 1e9+7;
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        long long ans = 0, prev = 0;
        for(int i = 0; i < s.length(); i++) {
            int num = s[i] - '0';
            prev = ((prev*10) % mod + (num*(i+1)) % mod) % mod;
            ans = (ans % mod + prev % mod) % mod;
        }
        return ans;
    }
};