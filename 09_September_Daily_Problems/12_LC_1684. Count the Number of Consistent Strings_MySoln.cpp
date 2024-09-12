class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowed_chars[26] = {0}, consistent=0;
        for(char ch : allowed){
            allowed_chars[ch-'a']++;
        }
        for(string word : words){
            bool is_allowed = true;
            for(char ch : word){
                if(!allowed_chars[ch-'a']){
                    is_allowed = false;
                    break;
                }
            }
            if(is_allowed)
                consistent++;
        }
        return consistent;
    }
};