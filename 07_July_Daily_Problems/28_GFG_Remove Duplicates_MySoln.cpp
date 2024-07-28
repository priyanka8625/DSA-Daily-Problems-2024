class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        int alpha[26] = {0};
        string ans="";
        for(char ch:str){
            if(alpha[ch-'a']==1){
                continue;
            }
            ans.push_back(ch);
            alpha[ch-'a']++;
        }
        return ans;
    }
};