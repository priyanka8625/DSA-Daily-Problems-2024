class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int i=0;
        string ans="", temp="";
        while(i<str.length()){
            temp = "";
            while(i<str.length() && str[i]!='.'){
                temp.push_back(str[i]);
                i++;
            }
            ans = '.'+temp+ans;
            i++;
        }
        ans.erase(ans.begin()+0);
        return ans;
    }
};