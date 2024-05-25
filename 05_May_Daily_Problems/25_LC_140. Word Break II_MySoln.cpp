class Solution {
private:
    unordered_set<string> dict;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string temp="";
        vector<string> ans;
        //store words in set
        for(string word : wordDict)
            dict.insert(word);

        getSegments(s, 0, temp, ans);
        return ans;
    }
    void getSegments(string &s, int index, string &temp, vector<string>& ans){
        if(index == s.length()){
            //remove the extra space of last word 
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        //add chars into temp untill we get a valid dictionary word
        int originalLength = temp.length();
        string word="";
        for(int i=index; i<s.length(); i++){
            word.push_back(s[i]);
            if(dict.find(word) != dict.end()){
                //add a space after this word and call for next index
                temp += word + " ";
                getSegments(s, i+1, temp, ans);
                temp.resize(originalLength);//backtrack 
            }
        }
    }
};