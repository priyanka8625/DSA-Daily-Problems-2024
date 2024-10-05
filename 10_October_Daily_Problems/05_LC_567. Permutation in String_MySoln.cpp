class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(char ch : s1){
            freq[ch-'a']++;
        }

        int start=0, end=0, n=s2.length(), remain=s1.length();
        while(end<n){
            //decrease char count if it's in s1
            if(freq[s2[end]-'a']>0){
                remain--;
            }
            freq[s2[end]-'a']--;
            end++;

            if(remain==0){
                return true;
            }

            if(end-start+1 > s1.length()){
                if(freq[s2[start]-'a']>=0)
                    remain++;
                freq[s2[start]-'a']++;
                start++;
            }
        }
        return false;
    }
};