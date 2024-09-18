class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> str_nums(n);
        for(int i=0; i<n; i++){
            str_nums[i] = to_string(nums[i]);
        }
        sort(str_nums.begin(), str_nums.end(), [&](const auto a, const auto b){
            return ((a+b) > (b+a));
        });
        string ans="";
        for(string s : str_nums){
            ans += s;
        }
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};