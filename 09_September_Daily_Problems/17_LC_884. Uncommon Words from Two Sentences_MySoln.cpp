class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string, int> mp;
        string word = "";
        for(int i=0; i<s1.length(); i++){
            word="";
            while(i<s1.length() && s1[i]!=' '){
                word.push_back(s1[i++]);
            }
            mp[word]++;
        }
        for(int i=0; i<s2.length(); i++){
            word="";
            while(i<s2.length() && s2[i]!=' '){
                word.push_back(s2[i++]);
            }
            mp[word]++;
        }
        for(auto it : mp){
            if(it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};