class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans="";
        int i=0, len=INT_MAX;
        for(string s: arr){
            len = min(len, (int)s.length());
        }
        while(i<len){
            char exp = arr[0][i];
            for(string s: arr){
                if(exp != s[i]){
                    return ans==""?"-1":ans;
                }
            }
            ans.push_back(exp);
            i++;
        }
        return ans==""?"-1":ans;
    }
};